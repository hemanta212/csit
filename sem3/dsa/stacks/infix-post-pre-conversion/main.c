#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.c"

#include "infix_postfix.c"
#include "postfix_calc.c"

void input(char *message, char *str);
void evalInfixToPostfix();
void postfixEval();

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage  ./main [prefix/postfix/prefix-eval/postfix-eval]\n");
    return 1;
  }
  char *argument = argv[1];
  if (strcmp(argument, "prefix") == 0) {
    evalInfixToPostfix();
  } else if (strcmp(argument, "postfix") == 0) {
    evalInfixToPostfix();
  } else if (strcmp(argument, "postfix-eval") == 0) {
    postfixEval();
  } else if (strcmp(argument, "prefix-eval") == 0) {
    postfixEval();
  } else {
    printf("Invalid argument %s.\nUsage ./main "
           "[prefix/postfix/prefix-eval/postfix-eval]\n",
           argument);
  }
}

void evalInfixToPostfix() {
  Stack *stack = NULL;

  char input_line[1024];
  input("Expression: ", input_line);

  for (int i = 0; i <= (int)strlen(input_line); i++) {
    char ch = input_line[i];
    if (ch == '\0')
      break;
    else if (ch == ' ')
      continue;

    postfixProcessChar(input_line[i], &stack);
  }
  postfixCleanup(&stack);
  freeStack(stack);
  puts("");
}

void postfixEval() {
  Stack *stack = NULL;

  char eval_line[1024];
  input("Expression: ", eval_line);
  calculatePostfix(eval_line, &stack);
  printf("Result: %s\n", pop(&stack));
}

void input(char *message, char *str) {
  printf("%s", message);
  scanf("%[^\n]", str);
}
