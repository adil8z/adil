#include "init.h"
#define SIZE 15
// initialize a matrix
void init_matrix(int m[SIZE][SIZE], int typ)
{
  int i, j, val = 0;
  
  for (i = 0; i < SIZE; i++)
    for (j = 0; j < SIZE; j++)
      m[i][j] = val++;
  		
}
