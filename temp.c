// Stack implementation in C
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int size;
  Stack *next;
  Stack *prev;
} Stack;

int main() { Stack *stack = malloc(sizeof(Stack)); }
