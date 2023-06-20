#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "blaz.h"
#include <signal.h> 
#include <sys/wait.h>
#include <time.h>

#define N 1 /* Repeter le programme pour mesurer l'energie */


void print_current_time() {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf("time and date: %s", asctime (timeinfo) );
}


int main(int argc, char* argv[])
{
    /* SETUP */
    clock_t start_t, end_t;
    int pidFils;

    /* Initialize arrays */
    Blaz_Matrix *matrixA, *matrixB;
    matrixA = blaz_read_matrix("../libraries/blaz-master/data/cosexp1024.ubz");
    matrixB = blaz_read_matrix("../libraries/blaz-master/data/cosexp1024.ubz");


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
        for (int i = 0; i < N; i++) {
            /* perform operations on arrays */
            //compressed_matrixC = blaz_add_compressed(compressed_matrixA, compressed_matrixB);
            compressed_matrixC = blaz_mul_compressed(compressed_matrixA, compressed_matrixB);
        }
        end_t = clock();
        kill(pidFils, SIGINT);
        double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        printf("Total time: %f\n", total_t);
    }
}