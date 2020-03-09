/*
 * File: quicksort.c
 * ----------------
 * An optimized implementation of quicksort.
 *
 * Individual Assignment
 * Max Perea Düring
 * Uppsala University
 *
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int partition(int A[], int p, int r){
  int i = (rand() % (r-p+1)) + p;
  int tmp;
  tmp = A[i];
  A[i] = A[r];
  A[r] = tmp;
  i = p - 1;
  int x = A[r];
  for (int j = p; j < r; j++){
    if (A[j] <= x){
      i++;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  return i+1;
}

void quicksort_aux(int A[], int p, int r){
  if (p < r){
    int q = partition(A, p, r);
    quicksort_aux(A, p, q - 1);
    quicksort_aux(A, q + 1, r);
  }
}

void quicksort(int arr[], int len){
  srand(time(NULL));
  quicksort_aux(arr, 0, len - 1);
}

void printArray(int arr[], int size){
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(){
  int arr[] = {10, 7, 8, 9, 1, 5, 13, 14, 2, 17, 21, 2, 3};
  int len = sizeof(arr)/sizeof(arr[0]);
  printf("%d\n",len);
  quicksort(arr, len);
  printf("Sorted array: \n");
  printArray(arr, len);
  return 0;
}
