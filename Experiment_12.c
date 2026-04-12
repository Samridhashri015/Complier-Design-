#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0, j = 0;
char str[100], left[20], right[20];
char temp = 'Z';

// structure for operators
struct exp {
    int pos;
    char op;
} k[20];

// function declarations
void findopr();
void explore();
void fleft(int);
void fright(int);

int main()
{
    printf("\t\tINTERMEDIATE CODE GENERATION\n\n");
    printf("Enter the Expression: ");
    scanf("%s", str);

    findopr();
    explore();

    return 0;
}

// find operators based on precedence
void findopr()
{
    // highest precedence first
    char ops[] = {'/', '*', '+', '-'};
    
    for (int o = 0; o < 4; o++)
    {
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == ops[o])
            {
                k[j].pos = i;
                k[j].op = ops[o];
                j++;
            }
        }
    }
}

// generate intermediate code
void explore()
{
    int idx = 0;

    while (idx < j)
    {
        fleft(k[idx].pos);
        fright(k[idx].pos);

        printf("%c = %s %c %s\n", temp, left, k[idx].op, right);

        str[k[idx].pos] = temp; // replace with temp variable
        temp--;

        idx++;
    }
}

// get left operand
void fleft(int x)
{
    int w = 0;
    x--;

    while (x >= 0 && str[x] != '+' && str[x] != '-' &&
           str[x] != '*' && str[x] != '/')
    {
        if (str[x] != '$')
        {
            left[w++] = str[x];
            str[x] = '$';
        }
        x--;
    }

    left[w] = '\0';

    // reverse string
    strrev(left);
}

// get right operand
void fright(int x)
{
    int w = 0;
    x++;

    while (str[x] != '\0' && str[x] != '+' && str[x] != '-' &&
           str[x] != '*' && str[x] != '/')
    {
        if (str[x] != '$')
        {
            right[w++] = str[x];
            str[x] = '$';
        }
        x++;
    }

    right[w] = '\0';
}