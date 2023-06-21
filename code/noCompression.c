#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define N 30 /* repeat program to measure energy consumption */
#define NX 8192 /* array dimensions: width */
#define NY NX /* array dimension: height */


/* arraySum = arrayA + arrayB */
void add(double* arraySum, double* arrayA, double* arrayB, size_t nx, size_t ny) {
    size_t i, j;
        for (j = 0; j < ny; j++)
            for (i = 0; i < nx; i++) {
                arraySum[i + nx * j] = arrayA[i + nx * j] + arrayB[i + nx * j];
            }
}

/* arrayMul = arrayA * arrayB */
void mul(double* arrayMul, double* arrayA, double* arrayB, size_t nxA, size_t nyB, size_t nxB, size_t nyA) {
  if (nxA == nyB) {
    size_t i, j, k;
        for (j = 0; j < nyA; j++)
            for (i = 0; i < nxB; i++) {
              arrayMul[i + nxB * j] = 0;
              for (k = 0; k < nxA; k++)
                arrayMul[i + nxB * j] += arrayA[k + nxA * j] * arrayB[i + nxB * k];
            }
  } else
    fprintf(stderr, "Error: incompatible dimensions for dot product\n");
}

/* arrayMulC = c * arrayA */
void multiplyByConst(double* arrayMulC, double* arrayA, double c, size_t nx, size_t ny) {
    size_t i, j;
        for (j = 0; j < ny; j++)
            for (i = 0; i < nx; i++) {
                arrayMulC[i + nx * j] = c * arrayA[i + nx * j];
            }
}

int main(int argc, char* argv[])
{
    /* SETUP */
    clock_t start_t, end_t;
    int pidFils;
	
    /* allocate arrays of doubles */
    size_t nx = NX;
    size_t ny = NY;
    double* arrayA = malloc(nx * ny * sizeof(double));
    double* arrayB = malloc(nx * ny * sizeof(double));
    double* arrayC = malloc(nx * ny * sizeof(double));
    
    /* initialize arrays to be compressed */
    size_t i, j;
        for (j = 0; j < ny; j++)
            for (i = 0; i < nx; i++) {
                double x = 2.0 * i / nx;
                double y = 2.0 * j / ny;
                arrayA[i + nx * j] = exp(-(x * x + y * y));
                arrayB[i + nx * j] = exp(-(x * x + y * y));
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
        for (int i = 0; i < N; i++) {
            
            /* perform operations on arrays */
            //add(arrayC, arrayA, arrayB, nx, ny);
            //mul(arrayC, arrayA, arrayB, nx, ny, nx, ny);
            multiplyByConst(arrayC, arrayA, sqrt(2.0), nx, ny);

        }
        end_t = clock();
        kill(pidFils, SIGINT);
        double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        printf("Total time: %f\n", total_t);
        
        /* clean up */
        free(arrayA);
        free(arrayB);
        free(arrayC);
    }

}
