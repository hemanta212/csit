#include <stdio.h>

void exchg(int array[], int i, int j);

int partition(int array[], int lo, int hi){
  int i = lo+1, j = hi, par=array[lo];
  while(1){
      while(array[i] <= par){
        i++;
        if (i == hi) { break; }
     }

      while(array[j] > par){
        j--;
        if (j == lo){ break;}
     }

      if (j <= i) { break;}
      exchg(array, i, j);
  }
  exchg(array, lo, j);
  return j;
}

void quicksort(int array[], int lo, int hi){
  if (hi <= lo)
    return;
  int j = partition(array, lo, hi);
  quicksort(array, lo, j-1);
  quicksort(array, j+1, hi);
 }

void sort(int array[], int N){
   // TODO shuffle array in c
   quicksort(array, 0, N-1);
}

void exchg(int array[], int i, int j){
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
}

int main(){
  int array[] = {3,2,1,4,3};
  int N = sizeof(array)/sizeof(int);
  sort(array, N);

  for(int i=0; i<N; i++){
    printf("%d ", array[i]);
  }
  return 0;
}
