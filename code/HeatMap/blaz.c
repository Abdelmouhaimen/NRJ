#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "blaz.h"
#include <signal.h> 
#include <sys/wait.h>
#include <time.h>

#define N 200 /* Repeter le programme pour mesurer l'energie */
#define NX 1048 /* array dimensions: width */
#define NY 680 /* array dimension: height */
#define N_Hms 10 /* number of heatmaps */

int main(int argc, char* argv[])
{
    /* SETUP */ 
    clock_t start_t, end_t;
    int pidFils;
    double result;

    /* Read data from file */
    char data_filename[150];
    sprintf(data_filename, "../../libraries/blaz-master/data/cosexp%ix%i.ubz",NX, NY);


    /* Initialize arrays */
    Blaz_Compressed_Matrix *compressed_matrix_result;
    Blaz_Matrix **matrixes;
    matrixes = malloc(N_Hms * sizeof(Blaz_Matrix*));
    for (int i = 0; i < N_Hms; i++) {
        matrixes[i] = blaz_read_matrix(data_filename);
    }

    /* compress arrays */
    Blaz_Compressed_Matrix **compressed_matrixes;
    compressed_matrixes = malloc(N_Hms * sizeof(Blaz_Compressed_Matrix*));
    for (int i = 0; i < N_Hms; i++) {
        compressed_matrixes[i] = blaz_compress(matrixes[i]);
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
        for (int l = 0; l < N; l++)
            for(int i=0; i<N_Hms - 1; i++) {
                if (i == 0)
                    compressed_matrix_result = blaz_add_compressed(compressed_matrixes[0], compressed_matrixes[1]);
                else
                    compressed_matrix_result = blaz_add_compressed(compressed_matrix_result, compressed_matrixes[i+1]);
            }
            //compressed_matrix_result = blaz_mul_cst_compressed(compressed_matrix_result, 1 / N_Hms);
        kill(pidFils, SIGINT);
        end_t = clock();
        double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        printf("Total time: %f\n", total_t);
    }
    
}