#include <math.h>

char *intToStr(int value);
char *mysub(int first, int second);
char *myadd(int first, int second);
char *mymul(int first, int second);
char *mydiv(int first, int second);

void calculatePostfix(char *expression, Stack **stack) {
  int len = strlen(expression);
  for (int i = 0; i < len; i++) {
    char ch = expression[i];
    if (ch == ' ')
      continue;

    if (!isOperator(ch)) {
      push(stack, genStringFromChar(ch));
      continue;
    }
    int first = atoi(pop(stack));
    int second = atoi(pop(stack));
    switch (ch) {
    case '-':
      push(stack, mysub(second, first));
      break;
    case '+':
      push(stack, myadd(second, first));
      break;
    case '*':
      push(stack, mymul(second, first));
      break;
    case '/':
      push(stack, mydiv(second, first));
      break;
    default:
      printf("Error Unknown char %c\n", ch);
      break;
    }
  }
}

char *mysub(int a, int b) {
  int result = a - b;
  return intToStr(result);
}
char *myadd(int a, int b) {
  int result = a + b;
  return intToStr(result);
}
char *mymul(int a, int b) {
  int result = a * b;
  return intToStr(result);
}
char *mydiv(int a, int b) {
  int result = a / b;
  return intToStr(result);
}
char *intToStr(int value) {
  int length = snprintf(NULL, 0, "%d", value);
  /* printf(":: size of int %d is %d\n", value, length); */
  char *str = malloc(length + 1);
  sprintf(str, "%d", value);
  return str;
}
