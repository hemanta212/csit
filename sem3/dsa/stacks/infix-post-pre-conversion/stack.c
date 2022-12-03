// Stack implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
  char* value;
  struct Stack *next;
} Stack;

void lg(char* message){
  printf(":: %s\n", message);
}
int stackSize(Stack *parent);
void freeStack(Stack *parent);
char* genString(char* value);
void input(char* message, char* str);

Stack* newStack(char *value){
    Stack *stack = malloc(sizeof(Stack));
    stack->value = genString(value);
    stack->next = NULL;
    return stack;
}

void push(Stack **parent, char* value){
    Stack *stack = newStack(value);
    if (*parent == NULL){
         *parent = newStack(value);
         return;
    }
    stack->next = *parent;
    *parent = stack;
}

int isEmpty(Stack *parent){
    return stackSize(parent) == 0;
}

char* pop(Stack **parent){
    if (parent == NULL) {return NULL;}
    if(isEmpty(*parent)){
        return NULL;
    }
   char* value = genString((*parent)->value);
   Stack *copy = *parent;
   *parent = (*parent)->next;
   free(copy);
   return value;
}

char* peek(Stack **parent){
    if (parent == NULL) {return NULL;}
    if(isEmpty(*parent)){
        return NULL;
    }
   char* value = genString((*parent)->value);
   return value;
}

int stackSize(Stack *parent) {
    if (parent == NULL){
        return 0;
    }else if (parent ->value == NULL){
        return 0;
    }
    int size = 1;
    Stack *currStack = parent;
    while(currStack->next != NULL){
        size++;
        currStack = currStack->next;
    }
    return size;
}

void freeStack(Stack *parent){
    if (parent == NULL){
        return;
    }
    Stack *currStack = parent;
    while(currStack->next != NULL){
        Stack *toFree = currStack;
        currStack = currStack->next;
        free(toFree->value);
        free(toFree);
    }
}
