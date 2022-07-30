#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

int is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int op_priority(char op)
{
    if (op == '+' || op == '-')
        return 0;
    if (op == '*' || op == '*')
        return 1;
    printf("erro aqui na op priority...\n");
    exit(1);
}

int op_cmp(char op1, char op2)
{
    return op_priority(op1) - op_priority(op2);
}

int eval(int a, int b, char op)
{
    if (op == '+')
        return a+b;
    if (op == '-')
        return a-b;
    if (op == '/')
        return a/b;
    if (op == '*')
        return a*b;
    printf("erro aqui no eval...\n");
    exit(1);
}

int eval_infix(char* expr, int maxi, int i)
{
    int a, b, r;
    char op, nextop;

    if (maxi == i)
        return (int) expr[i] - '0';

    a = (int) (expr[i] - '0');
    b = (int) (expr[i+2] - '0');
    op = expr[i+1];

    if (i+2 >= maxi)
    {
        r = eval(a, b, op);
        return r;
    }

    nextop = expr[i+3];
    if (op_cmp(op, nextop) >= 0)
    {
        a = eval(a, b, op);
        b = eval_infix(expr, maxi, i+4);
        r = eval(a, b, nextop);
        return r;
    } else {
        b = eval_infix(expr, maxi, i+2);
        r = eval(a, b, op);
        return r;
    }
}

int main()
{
    char c, *expression;
    const size_t expect_read = 1;
    int len, result;

    expression = malloc(MAXSIZE*sizeof(char));
    len = 0;

    while (scanf("%c", &c) == expect_read) 
    {
        if (c == ' ')
            continue;
        if (c == '\n')
            break;
        expression[len] = c;
        len += 1;
    }
    expression[len] = '\0';

    result = eval_infix(expression, len-1, 0);
    printf("%d\n", result);

    return 0;
}
