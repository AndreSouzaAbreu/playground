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
    if (op == '*' || op == '/')
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

int eval_infix(char* expr, int maxi)
{
    int st1[50];
    char st2[50];
    int a, b, r, i, j, t1, t2;
    char op, nextop;


    i= 0;
    a = 0;
    t1 = t2 = -1;
    // printf("i=%d maxi=%d\n", i, maxi);
    while (i <= maxi)
    {

        // printf("st1: ");
        // for (int k = 0; k <= t1; k+=1) {
        //     printf("%d ", st1[k]);
        // }
        // printf("\n");
        // printf("st2: ");
        // for (int k = 0; k <= t2; k+=1) {
        //     printf("%c ", st2[k]);
        // }
        // printf("\n");
 
        if (a == 0)
        {
            while ('0' <= expr[i] && expr[i] <= '9')
            {
                a = a*10 + (int) (expr[i] - '0');
                i += 1;
            }

            if (i > maxi)
            {
                t1 += 1;
                st1[t1] = a;
                break;
            }
        }

        op = expr[i];
        i += 1;

        j = 0;
        b = 0;
        while ('0' <= expr[i] && expr[i] <= '9')
        {
            b = b*10 + (int) (expr[i] - '0');
            i += 1;
            j += 1;
        }

        if (i > maxi)
        {
            r = eval(a, b, op);
            t1 += 1;
            st1[t1] = r;
            break;
        }

        nextop = expr[i];
        int cmp = op_cmp(op, nextop);

        if (cmp == 0)
        {
            a = eval(a, b, op);
            continue;
        }

        if (cmp > 0)
        {
            r = eval(a, b, op);
            t1 += 1;
            st1[t1] = r;
            t2 += 1;
            st2[t2] = nextop;
            i += 1;
        } else {
            t1 += 1;
            st1[t1] = a;
            t2 += 1;
            st2[t2] = op;
            i -= j;
        }
        a = 0;
    }

    // printf("st1: ");
    // for (int k = 0; k <= t1; k+=1) {
    //     printf("%d ", st1[k]);
    // }
    // printf("\n");
    // printf("st2: ");
    // for (int k = 0; k <= t2; k+=1) {
    //     printf("%c ", st2[k]);
    // }
    // printf("\n");

    r = st1[0];
    i = 1, j=0;
    while (j <= t2 && i <= t1)
    {
        b = st1[i];
        op = st2[j];
        r = eval(r, b, op);
        i += 1;
        j += 1;
    } 

    return r;
}

int main()
{
    char c, *expression;
    const size_t expect_read = 1;
    int len;
    int result;

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

    result = eval_infix(expression, len-1);
    printf("%d\n", result);

    return 0;
}
