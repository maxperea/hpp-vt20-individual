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

void quicksort(int A[], int p, int r){
  if (p < r){
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
    int q = i+1;
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
}
