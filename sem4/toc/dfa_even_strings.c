// Implementation of DFA that accepts all the strings starting from ‘ab’ and ends with b.

#include <stdio.h>

enum
{
    q0 = 0,
    q1,
    q2,
};
const int FINAL_STATES[] = {q2};

struct state
{
    int paths[1];
} states[] = {
    [q0] = {{q1}},
    [q1] = {{q2}},
    [q2] = {{q1}},
};

int transition(int state, char c)
{
    // return next state
    return states[state].paths[0];
}

int dfa(const char *input)
{
    int state = q0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        state = transition(state, input[i]);
        if (state == -1)
            break;
    }
    return state;
}

int main()
{
    char input[100];
    printf("Enter input string: ");
    scanf("%s", input);

    int state = dfa(input);

    if (state == -1)
        printf("Invalid input string\n");

    // if state is final state sets, accept
    int final_state_sz = sizeof(FINAL_STATES) / sizeof(int);
    for (int i = 0; i < final_state_sz; i++)
    {
        if (state == FINAL_STATES[i])
        {
            printf("Accepted\n");
            return 0;
        }
    }

    printf("Rejected\n");
    return 0;
}
