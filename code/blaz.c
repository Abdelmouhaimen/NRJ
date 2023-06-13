#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "blaz.h"

int main(int argc, char* argv[])
{
    Blaz_Matrix *matrixA, *matrixB;
    /* allocate array of doubles */
    size_t nx = 100;
    size_t ny = 100;
    double* arrayA = malloc(nx * ny * sizeof(double));
    double* arrayB = malloc(nx * ny * sizeof(double));

    /* initialize arrays to be compressed */
    /*
    size_t i, j;
        for (j = 0; j < ny; j++)
            for (i = 0; i < nx; i++) {
                double x = 2.0 * i / nx;
                double y = 2.0 * j / ny;
                arrayA[i + nx * j] = exp(-(x * x + y * y));
                arrayB[i + nx * j] = exp(-(x * x + y * y));
            }
    matrixA = malloc(sizeof(Blaz_Matrix));
    matrixB = malloc(sizeof(Blaz_Matrix));
    matrixA->matrix = arrayA;
    matrixB->matrix = arrayB;
    matrixA->width, matrixB->width = nx;
    matrixA->height, matrixB->height = ny;
    */
    
    matrixA = blaz_read_matrix("../libraries/blaz-master/data/cossqrt_64.ubz");
    matrixB = blaz_read_matrix("../libraries/blaz-master/data/xy_64.ubz");


    printf("PID : %i\n", getpid());
    sleep(0);
    printf("STARTED\n");

    /* compress arrays */
    Blaz_Compressed_Matrix *compressed_matrixC, *compressed_matrixA, *compressed_matrixB;

    compressed_matrixA = blaz_compress(matrixA);
    compressed_matrixB = blaz_compress(matrixB);
    
    compressed_matrixC = blaz_add_compressed(compressed_matrixA, compressed_matrixB);

    printf("DONE\n");
    sleep(5);
    free(arrayA);
    free(arrayB);
}