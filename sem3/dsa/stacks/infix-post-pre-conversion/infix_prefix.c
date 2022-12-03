void prefixProcessOperator(char ch, Stack **stack);

void prefixProcessChar(char ch, Stack **stack) {
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
    prefixProcessOperator(ch, stack);
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

void prefixProcessOperator(char ch, Stack **stack) {
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
