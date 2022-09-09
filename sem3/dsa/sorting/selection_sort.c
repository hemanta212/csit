#include <stdio.h>

void exchange(int i, int j, int array[]);

void selection_sort(int array[], int N){
  for (int i=0; i<N; i++){
    int a_min = i;
    for(int j=i+1; j<N; j++)
      if (array[j] < array[a_min])
        a_min = j;
    exchange(i, a_min, array);
  }
}

void exchange(int i, int j, int array[]){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

int main(){
  int array[] = {5,3,0,4,2,5};
  int N = sizeof(array)/sizeof(int);
  selection_sort(array, N);
  for (int i=0; i<N; i++){
    printf("%d ", array[i]);
  }
}
