#include "multiply.h"
#define SIZE 15
// thread function: taking "slice" as its argument

int num_thrd;   // number of threads
 
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

void* multiply(void* slice)
{
  int s = (int)slice;   // retrive the slice info
  int from = (s * SIZE)/num_thrd; // note that this 'slicing' works fine
  int to = ((s+1) * SIZE)/num_thrd; // even if SIZE is not divisible by num_thrd
  int i,j,k;
 
  printf("computing slice %d (from row %d to %d)\n", s, from, to-1);
  for (i = from; i < to; i++)
  {  
    for (j = 0; j < SIZE; j++)
    {
      C[i][j] = 0;
      for ( k = 0; k < SIZE; k++)
 C[i][j] += A[i][k]*B[k][j];
    }
  }
  printf("finished slice %d\n", s);
  return 0;
}

