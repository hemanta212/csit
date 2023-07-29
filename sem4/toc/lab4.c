/* Implementation of DFA that accepts 'while' and 'for keyword in C language'*/
#include <stdio.h>
enum states
{
    q0,
    q1,
    q2,
    q3,
    q4,
    q5,
    q6,
    qf,
    qd
};
enum states transition(enum states, char);
int main()
{

    /* FOR EVERY DFA */
    char input[20];
    enum states cur_state = q0;
    int i = 0;
    printf("Enter input string: ");
    scanf("%s", input);
    char ch = input[i];
    while (ch != '\0')
    {
        cur_state = transition(cur_state, ch);
        ch = input[++i];
    }
    if (cur_state == qf)
        printf("Accepted\n");
    else
        printf("Rejected\n");
    return 0;
    /* FOR EVERY DFA */
}

enum states transition(enum states s, char ch)
{

    enum states cur_state;
    switch (s)
    {

    case q0:
        if (ch == 'f')
            cur_state = q1;
        else if (ch == 'w')
            cur_state = q3;

        break;

    case q1:
        if (ch == 'o')
            cur_state = q2;
        else
            cur_state = qd;
        break;

    case q2:
        if (ch == 'r')
            cur_state = qf;
        else
            cur_state = qd;
        break;
    case q3:
        if (ch == 'h')
            cur_state = q4;
        else
            cur_state = qd;
        break;
    case q4:
        if (ch == 'i')
            cur_state = q5;
        else
            cur_state = qd;
        break;
    case q5:
        if (ch == 'l')
            cur_state = q6;
        else
            cur_state = qd;
        break;
    case q6:
        if (ch == 'e')
            cur_state = qf;
        else
            cur_state = qd;
        break;
    case qf:
        cur_state = qd;
    case qd:
        cur_state = qd;
    }
    return cur_state;
}