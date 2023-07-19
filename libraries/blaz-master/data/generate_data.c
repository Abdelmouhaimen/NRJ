/*******************************************************
 * This file is part of the Blaz library
 * @Name ........ : generate_data.c
 * @Role ........ : generation of uncompressed data sets to 
 *                  test the blaz library
 * @Author ...... : Matthieu Martel
 * @Version ..... : V1.1 23/03/2022
 * @Licence ..... : GPL V3
 * @Link ........ : https://github.com/mmartel66/blaz.git
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
  int i, j;
  double x, y, step_x, step_y;
  FILE *f;
  int nx = 1048;
  int ny = 680;
  double d;

  char filename[20];
  sprintf(filename, "cosexp%ix%i.ubz", nx, ny);
  f = fopen(filename,"w");

  int a = fwrite(&nx,sizeof(int),1,f);
  int b = fwrite(&ny,sizeof(int),1,f);

  step_x = 4.0 / nx;
  step_y = 4.0 / ny;
  y = -2.0;

  for(i=0;i<ny;i++) {
    x = -2.0;
    for(j=0;j<nx;j++) {
      d = cos(x*x +y*y)*exp(-0.1*(x*x+y*y)) ;
      fwrite(&d,sizeof(double),1,f);
      x += step_x;
    }
    y += step_y;
  }
  fclose(f);
}

