#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "blaz.h"
#include <signal.h> 
#include <sys/wait.h>
#include <time.h>

void print_current_time() {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf("time and date: %s", asctime (timeinfo) );
}


int main(int argc, char* argv[])
{
    Blaz_Matrix *matrixA, *matrixB;
    
    matrixA = blaz_read_matrix("../libraries/blaz-master/data/mydata_8K.ubz");
    matrixB = blaz_read_matrix("../libraries/blaz-master/data/mydata_8K.ubz");


    /* compress arrays */
    Blaz_Compressed_Matrix *compressed_matrixC, *compressed_matrixA, *compressed_matrixB;

    
    
    int pidFils = fork();
    if (pidFils == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pidFils == 0) {
        char ppid[10];
        sprintf(ppid, "%d", getppid());
        execlp("powerjoular", "powerjoular","-p", ppid, NULL);

        /*char N[10];
        sprintf(N, "%d", 1000);
        execl("./jouleit.sh","./jouleit.sh", "-n", N, NULL);*/
        perror("execlp failed");

        exit(EXIT_FAILURE);
    }
    else {
        /* add compressed arrays */
        //printf("START : ");
        //print_current_time(); // Print start time
        compressed_matrixA = blaz_compress(matrixA);
        compressed_matrixB = blaz_compress(matrixB);
        
        compressed_matrixC = blaz_add_compressed(compressed_matrixA, compressed_matrixB);
        //printf("FINISH : ");
        //print_current_time(); // Print finish time
        //sleep(5);
        kill(pidFils, SIGINT);
    }
}