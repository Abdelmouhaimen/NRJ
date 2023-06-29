#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "blaz.h"
#include <signal.h> 
#include <sys/wait.h>
#include <time.h>

#define N 128 /* Repeter le programme pour mesurer l'energie */
#define NX 128 /* array dimensions: width */
#define NY NX /* array dimension: height */

int main(int argc, char* argv[])
{
    /* SETUP */ 
    clock_t start_t, end_t;
    int pidFils;
    double result;

    /* Initialize arrays */
    Blaz_Matrix *matrixA, *matrixB;
    char data_filename[150];
    sprintf(data_filename, "../libraries/blaz-master/data/cosexp%d.ubz", NX);
    matrixA = blaz_read_matrix(data_filename);
    matrixB = blaz_read_matrix(data_filename);


    /* compress arrays */
    Blaz_Compressed_Matrix *compressed_matrixC, *compressed_matrixA, *compressed_matrixB;
    compressed_matrixA = blaz_compress(matrixA);
    compressed_matrixB = blaz_compress(matrixB);

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
            /* perform operations on arrays */
            //compressed_matrixC = blaz_add_compressed(compressed_matrixA, compressed_matrixB);
            compressed_matrixC = blaz_mul_compressed(compressed_matrixA, compressed_matrixB);
            //compressed_matrixC = blaz_mul_cst_compressed(compressed_matrixA, sqrt(2.0));
            /*for(int i=0; i<NY; i++)
                for(int j=0; j<NX; j++)
                    result = blaz_dot_product_compressed(compressed_matrixA, compressed_matrixB, i, j);*/
        }
        kill(pidFils, SIGINT);
        end_t = clock();
        double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        printf("Total time: %f\n", total_t);
    }
}