#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "init.h"
#include "printmat.h"
#include "multiply.h" 
#define SIZE 15  // Size by SIZE matrices
#define SIZE2 1   // Size by SIZE matrices
int num_thrd = 2;   // number of threads
 
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

 

 
int main(int argc, char* argv[])
{
  pthread_t* thread;  // pointer to a group of threads
  int i;
 
  
  init_matrix(A,0);
  init_matrix(B,1);
  thread = (pthread_t*) malloc(num_thrd*sizeof(pthread_t));
  clock_t begin, end;
  float time_spent;
  
  begin = clock();	
// this for loop not entered if threadd number is specified as 1
  for (i = 1; i < num_thrd; i++)
  {
    // creates each thread working on its own slice of i
    if (pthread_create (&thread[i], NULL, multiply, (void*)i) != 0 )
    {
      perror("Can't create thread");
      free(thread);
      exit(-1);
    }
  }
 
  // main thread works on slice 0
  // so everybody is busy
  // main thread does everything if threadd number is specified as 1
  multiply(0);
 
  // main thead waiting for other thread to complete
  for (i = 1; i < num_thrd; i++)
 pthread_join (thread[i], NULL);
 
  //printf("\n\n");
  //print_matrix(A);
 // printf("\n\n\t       * \n");
  //print_matrix(B);
  //printf("\n\n\t       = \n");
 // print_matrix(C);
  //printf("\n\n");
  end = clock();
  time_spent = (float)(end - begin) / CLOCKS_PER_SEC;	
  printf("\nCalculation Done\n");
  printf("\nTime Spent: %f",time_spent,"\n");
  printf("\n");
  free(thread);
 
  return 0;
 
}
