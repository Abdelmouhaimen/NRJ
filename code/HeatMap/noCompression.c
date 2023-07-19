#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define N 50 /* repeat program to measure energy consumption */
#define N_Hms 10 /* number of operations */
#define NX 1048 /* array dimensions: width */
#define NY 680 /* array dimension: height */



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
double* multiplyByConst(double* arrayA, double c, size_t nx, size_t ny) {
    double* arrayMulC = malloc(nx * ny * sizeof(double));
    int i, j;   
    for (j = 0; j < ny; j++)
        for (i = 0; i < nx; i++) {
            arrayMulC[i + nx * j] = c * arrayA[i + nx * j];
        }
    return arrayMulC;
}


int main(int argc, char* argv[])
{
    /* SETUP */
    double** arrays = malloc(N_Hms * sizeof(double*));
    void** buffers = malloc(N_Hms * sizeof(void*));
    clock_t start_t, end_t;
    int pidFils;
    size_t nx = NX;
    size_t ny = NY;

    /* initialize result array */
    void* buffer_result;
    double* array_result;

    
    /* initialize arrays */
    for (int l = 0; l < N_Hms; l++){
        arrays[l] = malloc(nx * ny * sizeof(double));
        /* allocate memory */
        for (int j = 0; j < ny; j++)
            for (int i = 0; i < nx; i++) {
                double x = 2.0 * i / nx;
                double y = 2.0 * j / ny;
                arrays[l][i + nx * j] = exp(-(x * x + y * y));
            }
    }

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
            for(int i=0; i<N_Hms - 1; i++) {
                /* perform operation */
                if (i == 0) {
                    array_result = add(arrays[0], arrays[1], nx, ny);
                } else
                    array_result = add(array_result, arrays[i+1], nx, ny);
                array_result = multiplyByConst(array_result, 1 / N_Hms, nx, ny);
            }
        }
        kill(pidFils, SIGINT);
        end_t = clock();
        double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        printf("Total time: %f\n", total_t);
        
        /* clean up */
        for (int l = 0; l < N_Hms - 1; l++) {
            free(buffers[l]);
            free(arrays[l]);
        }
        free(buffers);
        free(arrays);
        free(array_result);
        free(buffer_result);
    }

}