#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
enum states
{
    q0,
    q1,

};
enum states transition(enum states, char, char);
typedef struct
{
    char data[MAX];
    int top;
} Stack;
;
void push(Stack *stack, char element)
{
    stack->data[++(stack->top)] = element;
}
void initStack(Stack *stack)
{
    stack->top = -1;
}

void pop(Stack *stack)
{
    stack->top = stack->top - 1;
}
bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}
char checkTop(Stack *stack)
{
    if (isEmpty(stack))
        return 'z';
    return stack->data[(stack->top)];
}
bool isAccepted(char *input);
int main()
{
    char input[20];
    enum states cur_state = q0;

    printf("Enter input string: ");
    scanf("%s", input);
    int i = 0;

    if (isAccepted(input))
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }

    return 0;
}

bool isAccepted(char *input)
{
    Stack st;
    initStack(&st);
    enum states cur_state = q0;
    int len = strlen(input);
    int i = 0;
    // Check the input string
    while (i < len)
    {
        char top = checkTop(&st);
        char ch = input[i];
        if (cur_state == q0)
        {
            if (ch == 'a' && top == 'z' || ch == 'a' && top == 'a')
            {
                cur_state = q0;

                push(&st, 'a');
            }

            else if (ch == 'b' && top == 'a')
            {
                cur_state = q1;
                pop(&st);
            }
            else
            {
                break;
            }
        }
        else if (cur_state == q1)
        {
            if (ch == 'b' && top == 'a')
            {
                pop(&st);
                cur_state = q1;
            }
            else
            {
                break;
            }
        }

        i++;
    }

    return (isEmpty(&st) && i == len);
}
