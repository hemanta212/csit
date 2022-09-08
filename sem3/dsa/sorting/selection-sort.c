// Selection sort algorithm
#include <stdio.h>

void swap(int array[], int i, int j) {
  int temp = array[j];
  array[j] = array[i];
  array[i] = temp;
}

void selection_sort(int array[], int N) {
  for (int i = 0; i < N; i++) {
    int min = i;
    for (int j = i + 1; j < N; j++)
      if (array[j] < array[min])
        min = j;
    swap(array, i, min);
  }
}

int main() {
  int array[6] = {4, 0, 4, 3, 2, 1};
  int N = sizeof(array) / sizeof(int);
  selection_sort(array, N);
  printf("[ ");
  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }
  printf("]\n");
}
