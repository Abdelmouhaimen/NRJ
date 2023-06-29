#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "blaz.h"
#include <signal.h> 
#include <sys/wait.h>
#include <time.h>

#define N 10 /* Repeter le programme pour mesurer l'energie */
#define N_OPs 256 /* number of operations */
#define NX 128 /* array dimensions: width */
#define NY NX /* array dimension: height */

int main(int argc, char* argv[])
{
    /* SETUP */ 
    clock_t start_t, end_t;
    int pidFils;
    double result;

    /* Read data from file */
    char data_filename[150];
    sprintf(data_filename, "../../libraries/blaz-master/data/cosexp%d.ubz", NX);

    /* Initialize arrays */
    Blaz_Compressed_Matrix *compressed_matrix_result;
    Blaz_Matrix **matrixes;
    matrixes = malloc((N_OPs + 1) * sizeof(Blaz_Matrix*));
    for (int i = 0; i < N_OPs + 1; i++) {
        matrixes[i] = blaz_read_matrix(data_filename);
    }
    

    /* compress arrays */
    Blaz_Compressed_Matrix **compressed_matrixes;
    compressed_matrixes = malloc((N_OPs + 1) * sizeof(Blaz_Compressed_Matrix*));
    for (int i = 0; i < N_OPs + 1; i++) {
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
            for(int i=0; i<N_OPs; i++) {
                if (i == 0)
                    compressed_matrix_result = blaz_add_compressed(compressed_matrixes[0], compressed_matrixes[1]);
                else {
                    if (i % 2 == 0)
                        compressed_matrix_result = blaz_add_compressed(compressed_matrix_result, compressed_matrixes[i+1]);
                    else
                        compressed_matrix_result = blaz_mul_compressed(compressed_matrix_result, compressed_matrixes[i+1]);
                }
            }
        kill(pidFils, SIGINT);
        end_t = clock();
        double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        printf("Total time: %f\n", total_t);
    }
}