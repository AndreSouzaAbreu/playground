#include <stdio.h>
#include <unistd.h>

char TEXT[4096] = { 0 };
unsigned char DATA[16384] = { 0 };
char symbols[8] = {'+', '-', '<', '>', ',', '.', '[', ']'};

int I = 0;
int D = 0;

int main(int argc, char** argv)
{
    FILE* f;
    char c;
    int i;

    f = fopen(argv[1], "r");
    while (1) 
    {
        c = getc(f);
        if (feof(f))
            break;
        for (i = 0; i < 8; i+=1)
        {
            if (c == symbols[i])
            {
                TEXT[I] = c;
                I = I+1;
                break;
            }
        }
        
    }
    fclose(f);

    I = 0;
    while (TEXT[I] != 0)
    {
        if (TEXT[I] == '+') {
            DATA[D] += 1;
        } else if (TEXT[I] == '-') {
            DATA[D] -= 1;
        } else if (TEXT[I] == '>') {
            D += 1;
        } else if (TEXT[I] == '<') {
            D -= 1;
        } else if (TEXT[I] == ',') {
            DATA[D] = (unsigned char) getchar();
        } else if (TEXT[I] == '.') {
            putchar(DATA[D]);
        } else if (TEXT[I] == '[') {
            if (DATA[D] == 0)
            {
                i = 1;
                while (i != 0)
                {
                    I += 1;
                    if (TEXT[I] == '[')
                        i += 1;
                    else if (TEXT[I] == ']')
                        i -= 1;
                }
            }
        } else if (TEXT[I] == ']') {
            if (DATA[D] != 0)
            {
                i = 1;
                while (i != 0)
                {
                    I -= 1;
                    if (TEXT[I] == ']')
                        i += 1;
                    else if (TEXT[I] == '[')
                        i -= 1;
                }
            }
        }
        I += 1;
    }

    return 0;
}
