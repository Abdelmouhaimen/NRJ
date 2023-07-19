#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "zfp.h"
#include <signal.h>
#include <time.h>

#define N 2 /* repeat program to measure energy consumption */
#define NX 8192 /* array dimensions: width */
#define NY NX /* array dimension: height */
#define RATE 5.6 /* desired compression rate */

/* compress or decompress array */
static int
compress(double* array, void** buffer, size_t nx, size_t ny, zfp_bool decompress)
{
    int status = 0;    /* return value: 0 = success */
    zfp_type type;     /* array scalar type */
    zfp_field* field;  /* array meta data */
    zfp_stream* zfp;   /* compressed stream */
    //void* buffer;      /* storage for compressed stream */
    size_t bufsize;    /* byte size of compressed buffer */
    bitstream* stream; /* bit stream to write to or read from */
    size_t zfpsize;    /* byte size of compressed stream */

    
    /* allocate meta data for the 2D array a[ny][nx] */
    type = zfp_type_double;
    field = zfp_field_2d(array, type, nx, ny);

    /* allocate meta data for a compressed stream */
    zfp = zfp_stream_open(NULL);

    /* set compression mode and parameters via one of four functions */
    /*  zfp_stream_set_reversible(zfp); */
    /*  zfp_stream_set_precision(zfp, precision); */
    /* zfp_stream_set_accuracy(zfp, tolerance); */
    zfp_stream_set_rate(zfp, RATE, type, zfp_field_dimensionality(field), zfp_false);

    /* allocate buffer for compressed data */
    bufsize = zfp_stream_maximum_size(zfp, field);
    if (!decompress) {
        *buffer = malloc(bufsize);
    }

    /* associate bit stream with allocated buffer */
    stream = stream_open(*buffer, bufsize);
    zfp_stream_set_bit_stream(zfp, stream);
    zfp_stream_rewind(zfp);
    /* compress or decompress entire array */
    if (decompress) {
        /* read compressed stream and decompress and output array */
        if (!zfp_decompress(zfp, field)) {
            fprintf(stderr, "decompression failed\n");
            status = EXIT_FAILURE;
        }
    }
    else {
        /* compress array and output compressed stream */
        zfpsize = zfp_compress(zfp, field);
        if (!zfpsize) {
            fprintf(stderr, "compression failed\n");
            status = EXIT_FAILURE;
        }        
    }

    /* clean up */
    zfp_field_free(field);
    zfp_stream_close(zfp);
    stream_close(stream);


    return status;
}

/* arraySum = arrayA + arrayB */
double* add(double* arrayA, double* arrayB, size_t nx, size_t ny) {
    double* arraySum = malloc(nx * ny * sizeof(double));
    int i, j;
        for (j = 0; j < ny; j++)
            for (i = 0; i < nx; i++) {
                arraySum[i + nx * j] = arrayA[i + nx * j] + arrayB[i + nx * j];
            }
    return arraySum;
}

/* arrayMul = arrayA * arrayB */
double* mul(double* arrayA, double* arrayB, size_t nxA, size_t nyB, size_t nxB, size_t nyA) {
    double* arrayMul;
    if (nxA == nyB) {
        arrayMul = malloc(nxB * nyA * sizeof(double));
        int i, j, k;
            for (j = 0; j < nyA; j++)
                for (i = 0; i < nxB; i++) {
                arrayMul[i + nxB * j] = 0;
                for (k = 0; k < nxA; k++)
                    arrayMul[i + nxB * j] += arrayA[k + nxA * j] * arrayB[i + nxB * k];
                }
    } else
        fprintf(stderr, "Error: incompatible dimensions for dot product\n");
    return arrayMul;
}

/* arrayMulC = c * arrayA */
void multiplyByConst(double* arrayMulC, double* arrayA, double c, size_t nx, size_t ny) {
    int i, j;   
        for (j = 0; j < ny; j++)
            for (i = 0; i < nx; i++) {
                arrayMulC[i + nx * j] = c * arrayA[i + nx * j];
            }
}

/* arrayC = arrayA(i,:) * arrayB(j,:) 
@Param n = nxA = nyB*/
double dotProduct(double* arrayA, double* arrayB, size_t n, size_t nxB, int i, int j) {
    size_t k;
    double result = 0;
    for (k = 0; k < n; k++)
        result += arrayA[k + n * i] * arrayB[j + nxB * k];
    return result;
}

int main(int argc, char* argv[])
{
    /* SETUP */
    double* arrayA, *arrayB, *arrayC;
    void* bufferA, *bufferB, *bufferC;
    clock_t start_t, end_t;
    int pidFils;
    double result;
	
    /* allocate arrays of doubles */
    size_t nx = NX;
    size_t ny = NY;
    arrayA = malloc(nx * ny * sizeof(double));
    arrayB = malloc(nx * ny * sizeof(double));
    
    /* initialize arrays to be compressed */
    int i, j;
        for (int j = 0; j < ny; j++)
            for (int i = 0; i < nx; i++) {
                double x = 2.0 * i / nx;
                double y = 2.0 * j / ny;
                arrayA[i + nx * j] = exp(-(x * x + y * y));
                arrayB[i + nx * j] = exp(-(x * x + y * y));
            }

    /* compress arrays */
    compress(arrayA, &bufferA, nx, ny, 0);
    compress(arrayB, &bufferB, nx, ny, 0);

    start_t = clock();

    if ((pidFils = fork()) == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pidFils == 0) {
        char ppid[10];
        sprintf(ppid, "%d", getppid());
        execlp("powerjoular", "powerjoular","-p", ppid, NULL);
        perror("execlp failed");
        exit(EXIT_FAILURE);
    }
    else {
        for (int l = 0; l < N; l++) {
            /* decompress arrays */
            compress(arrayA, &bufferA, nx, ny, 1);
            compress(arrayB, &bufferB, nx, ny, 1);
            
            /* perform operations on arrays */
            //arrayC = add(arrayA, arrayB, nx, ny);
            //arrayC = mul(arrayA, arrayB, nx, ny, nx, ny);
            //multiplyByConst(arrayC, arrayA, sqrt(2.0), nx, ny);
            result = dotProduct(arrayA, arrayB, nx, nx, 5, 5);

            /* compress arrays */
            //compress(arrayC, &bufferC, nx, ny, 0);
        }
        kill(pidFils, SIGINT);
        end_t = clock();
        double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        printf("Total time: %f\n", total_t);
        
        /* clean up */
        free(arrayA);
        free(arrayB);
        //free(arrayC);
        free(bufferA);
        free(bufferB);
        //free(bufferC);
    }

}
