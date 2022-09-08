// Stack implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
  char* value;
  struct Stack *next;
} Stack;

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

char* genString(char* value){
    char* str = malloc(sizeof(char) * strlen(value));
    strcpy(str, value);
    return str;
}

int main() {
    Stack *stack = NULL;

    char input_line[1024];
    input("stack:: ", input_line);
    char word[1024];
    int word_index = 0;
    for(int i=0; i <= (int)strlen(input_line); i++){
        if(input_line[i] != ' ' && input_line[i] != '\0'){
            word[word_index++] = input_line[i];
            continue;
        }
        word[word_index] = '\0';
        if(strcmp(word, "-")==0){
            printf("Popped: %s, size: %d\n", pop(&stack), stackSize(stack));
        }else{
            push(&stack, word);
        }
        word_index = 0;
        strcpy(word, "");
    }

    freeStack(stack);
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
    free(parent->value);
    free(parent);
}

void input(char* message, char* str){
    printf("%s", message);
    scanf("%[^\n]", str);
}
