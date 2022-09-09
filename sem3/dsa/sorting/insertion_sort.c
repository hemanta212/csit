#include <stdio.h>

void exchange(int i, int j, int array[]);

void insertion_sort(int array[], int N){
  for (int i=0; i<N; i++)
    for(int j=i; j>0; j--)
      if (array[j] < array[j-1])
        exchange(j, j-1, array);
}

void exchange(int i, int j, int array[]){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

int main(){
  int array[] = {5,3,0,4,2,5};
  int N = sizeof(array)/sizeof(int);
  insertion_sort(array, N);
  for (int i=0; i<N; i++){
    printf("%d ", array[i]);
  }
}
