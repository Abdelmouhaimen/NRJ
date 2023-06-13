/* minimal code example showing how to call the zfp (de)compressor */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "zfp.h"

/* compress or decompress array */
static int
compress(double* array, size_t nx, size_t ny, double tolerance, zfp_bool decompress)
{
  int status = 0;    /* return value: 0 = success */
  zfp_type type;     /* array scalar type */
  zfp_field* field;  /* array meta data */
  zfp_stream* zfp;   /* compressed stream */
  void* buffer;      /* storage for compressed stream */
  size_t bufsize;    /* byte size of compressed buffer */
  bitstream* stream; /* bit stream to write to or read from */
  size_t zfpsize;    /* byte size of compressed stream */

  /* allocate meta data for the 3D array a[ny][nx] */
  type = zfp_type_double;
  field = zfp_field_2d(array, type, nx, ny);

  /* allocate meta data for a compressed stream */
  zfp = zfp_stream_open(NULL);

  /* set compression mode and parameters via one of four functions */
/*  zfp_stream_set_reversible(zfp); */
/*  zfp_stream_set_rate(zfp, rate, type, zfp_field_dimensionality(field), zfp_false); */
/*  zfp_stream_set_precision(zfp, precision); */
  zfp_stream_set_accuracy(zfp, tolerance);

  /* allocate buffer for compressed data */
  bufsize = zfp_stream_maximum_size(zfp, field);
  buffer = malloc(bufsize);

  /* associate bit stream with allocated buffer */
  stream = stream_open(buffer, bufsize);
  zfp_stream_set_bit_stream(zfp, stream);
  zfp_stream_rewind(zfp);

  /* compress or decompress entire array */
  if (decompress) {
    /* read compressed stream and decompress and output array */
    zfpsize = fread(buffer, 1, bufsize, stdin);
    if (!zfp_decompress(zfp, field)) {
      fprintf(stderr, "decompression failed\n");
      status = EXIT_FAILURE;
    }
    else
        fwrite(array, sizeof(double), zfp_field_size(field, NULL), stdout);
  }
  else {
    /* compress array and output compressed stream */
    zfpsize = zfp_compress(zfp, field);
    if (!zfpsize) {
      fprintf(stderr, "compression failed\n");
      status = EXIT_FAILURE;
    }
    else
      fwrite(buffer, 1, zfpsize, stdout);
  }

  /* clean up */
  zfp_field_free(field);
  zfp_stream_close(zfp);
  stream_close(stream);
  free(buffer);

  return status;
}

void add(double* arraySum, double* arrayA, double* arrayB, size_t nx, size_t ny) {
    size_t i, j, k;
        for (j = 0; j < ny; j++)
            for (i = 0; i < nx; i++) {
                arraySum[i + nx * j] = arrayA[i + nx * j] + arrayB[i + nx * j];
            }
}

int main(int argc, char* argv[])
{
    /* allocate array of doubles */
    size_t nx = 500;
    size_t ny = 500;
    double* arrayA = malloc(nx * ny * sizeof(double));
    double* arrayB = malloc(nx * ny * sizeof(double));

    
    /* initialize arrays to be compressed */
    size_t i, j;
        for (j = 0; j < ny; j++)
            for (i = 0; i < nx; i++) {
                double x = 2.0 * i / nx;
                double y = 2.0 * j / ny;
                arrayA[i + nx * j] = exp(-(x * x + y * y));
                arrayB[i + nx * j] = exp(-(x * x + y * y));
            }
    
    FILE* terminal = fopen("/dev/tty", "w");
    fprintf(terminal,"PID : %i\n", getpid());
    sleep(10);
    fprintf(terminal,"STARTED\n");
    /* compress & decompress arrayA */
    compress(arrayA, nx, ny, 1e-3, 0);
    compress(arrayA, nx, ny, 1e-3, 1);

    /* compress & decompress arrayB */
    compress(arrayB, nx, ny, 1e-3, 0);
    compress(arrayB, nx, ny, 1e-3, 1);


    double* arrayC = malloc(nx * ny * sizeof(double));
    add(arrayC, arrayA, arrayB, nx, ny);

    compress(arrayC, nx, ny, 1e-3, 0);
    fprintf(terminal,"DONE\n");
    sleep(5);
    free(arrayA);
    free(arrayB);
    free(arrayC);

}
