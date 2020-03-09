#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort_rand.c"

void printArray(int arr[], int size){
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(){
  srand(time(NULL));

  int len = 10000;
  int *arr = malloc(sizeof(int)*len);;
  for (int i = 0; i < len; i++){
    //arr[i] = rand();
    arr[i] = i;
  }

  clock_t start, stop;

  start = clock();
  quicksort(arr, 0, len - 1);
  stop = clock();
  //printArray(arr, len);

  printf("Sorted array in %f seconds\n", (double) (stop - start) / CLOCKS_PER_SEC);
  return 0;
}
