int isOperator(char ch);
char *genString(char *value);
char *genStringFromChar(char ch);
void processOperator(char ch, Stack **stack);
int isHigherPrecedence(char op1, char op2);
void keepPoppingTill(Stack **stack, char *identifier);
void keepPoppingTillLowerPrecendence(Stack **stack);

void postfixProcessChar(char ch, Stack **stack) {
  /* printf(":: processing char %c\n", ch); */
  switch (ch) {
  case '(':
    /* printf(":: pushing to stack %c\n", ch); */
    push(stack, genStringFromChar(ch));
    break;
  case ')':
    /* printf(":: init paren popping %c\n", ch); */
    keepPoppingTill(stack, "(");
    break;
  case '*':
  case '/':
  case '+':
  case '-':
    /* printf(":: Found operator %c\n", ch); */
    processOperator(ch, stack);
    break;
  case ' ':
    break;
  default:
    printf("%c ", ch);
    break;
  }
}

void postfixCleanup(Stack **stack) {
  /* printf(":: all expression finished evaluating\n"); */
  if (isEmpty(*stack)) {
    /* printf(":: stack is empty. Done...\n"); */
    return;
  }
  /* printf(":: popping and printing everything now.\n"); */
  char *lastPopped = pop(stack);
  while (lastPopped != NULL) {
    printf("%s ", lastPopped);
    lastPopped = pop(stack);
  }
}

char *genString(char *value) {
  char *str = malloc(sizeof(char) * strlen(value));
  strcpy(str, value);
  return str;
}

char *genStringFromChar(char ch) {
  char str[] = {ch, '\0'};
  return genString(str);
}

int isOperator(char ch) {
  char operators[] = {'-', '*', '+', '/'};
  int sz = sizeof(operators) / sizeof(char);
  for (int i = 0; i < sz; i++) {
    if (operators[i] == ch)
      return 1;
  }
  return 0;
}

void processOperator(char ch, Stack **stack) {
  if (isEmpty(*stack)) {
    /* printf(":: empty stack pushing %c \n", ch); */
    push(stack, genStringFromChar(ch));
    return;
  } else if (!isOperator(peek(stack)[0])) {
    /* printf(":: last item ain't operator pushing %c \n", ch); */
    push(stack, genStringFromChar(ch));
    return;
  }
  char lastOperator = peek(stack)[0];
  if (isHigherPrecedence(ch, lastOperator)) {
    /* printf(":: i am higher nobler man, pushing %c \n", ch); */
    push(stack, genStringFromChar(ch));
  } else {
    /* printf(":: i am lowly :(, popping from %c \n", ch); */
    keepPoppingTillLowerPrecendence(stack);
    push(stack, genStringFromChar(ch));
  }
}

int isHigherPrecedence(char op1, char op2) {
  if (op2 == '*' || op2 == '/')
    return 0;

  if (op1 == '*' || op1 == '/')
    return 1;

  return 0;
}

void keepPoppingTill(Stack **stack, char *identifier) {
  char *lastPopped = pop(stack);
  while (strcmp(lastPopped, identifier) != 0) {
    printf("%s ", lastPopped);
    lastPopped = pop(stack);
  }
}

void keepPoppingTillLowerPrecendence(Stack **stack) {
  char *lastPopped = peek(stack);
  if (lastPopped == NULL) {
    return;
  }
  while (lastPopped[0] != '+' && lastPopped[0] != '-') {
    printf("%s ", lastPopped);
    pop(stack);
    lastPopped = peek(stack);
    if (lastPopped == NULL) {
      break;
    }
  }
}
