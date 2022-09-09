#include <stdio.h>

void merge(int array[], int aux[], int mid, int low, int high){
  // Takes an array, which is sorted from low to mid and mid+1 to high
  // This function merges these two halves together to get an ordered array

  // Copy operation
  for (int k=low; k<=high; k++)
    aux[k] = array[k];

  int i = low, j = mid+1;
  for (int k=low; k<=high; k++)
    if (i > mid) array[k] = aux[j++];
    else if (j > high) array[k] = aux[i++];
    else if (aux[i] < aux[j]) array[k] = aux[i++];
    else array[k] = aux[j++];
}

void mergesort(int array[], int aux[], int low, int high){
  if (low >= high) return;

  int mid = (int) low + (high - low) / 2;

  mergesort(array, aux, low, mid);
  mergesort(array, aux, mid+1, high);
  merge(array, aux, mid, low, high);
}

void sort(int array[], int N){
  int aux[N];
  mergesort(array, aux, 0, N-1);
}

int main(){
  int array[] = {1,2,3,9,0,2,5,3,0,6};
  int N = sizeof(array)/sizeof(int);

  sort(array, N);
  for (int i=0; i<N; i++){
    printf("%d ", array[i]);
  }
}
