#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void push(char *, int *, char);
char stacktop(char *);
void isproduct(char, char);
int ister(char);
int isnter(char);
int isstate(char);
void error();
void isreduce(char, char);
char pop(char *, int *);
void printt(char *, int *, char [], int);
void rep(char [], int);

// ACTION TABLE
struct action {
    char row[6][5];
};

const struct action A[12] = {
    {"sf","emp","emp","se","emp","emp"},
    {"emp","sg","emp","emp","emp","acc"},
    {"emp","rc","sh","emp","rc","rc"},
    {"emp","re","re","emp","re","re"},
    {"sf","emp","emp","se","emp","emp"},
    {"emp","rg","rg","emp","rg","rg"},
    {"sf","emp","emp","se","emp","emp"},
    {"sf","emp","emp","se","emp","emp"},
    {"emp","sg","emp","emp","sl","emp"},
    {"emp","rb","sh","emp","rb","rb"},
    {"emp","rb","rd","emp","rd","rd"},
    {"emp","rf","rf","emp","rf","rf"}
};

// GOTO TABLE
struct gotol {
    char r[3][4];
};

const struct gotol G[12] = {
    {"b","c","d"},
    {"emp","emp","emp"},
    {"emp","emp","emp"},
    {"emp","emp","emp"},
    {"i","c","d"},
    {"emp","emp","emp"},
    {"emp","j","d"},
    {"emp","emp","k"},
    {"emp","emp","emp"},
    {"emp","emp","emp"},
    {"emp","emp","emp"},
    {"emp","emp","emp"}
};

// Terminals & Non-terminals
char ter[6] = {'i','+','*',')','(','$'};
char nter[3] = {'E','T','F'};
char states[12] = {'a','b','c','d','e','f','g','h','m','j','k','l'};

// Stack
char stack[100];
int top = -1;
char temp[10];

// Grammar rules
struct grammar {
    char left;
    char right[10];
};

const struct grammar rl[6] = {
    {'E',"E+T"},
    {'E',"T"},
    {'T',"T*F"},
    {'T',"F"},
    {'F',"(E)"},
    {'F',"i"}
};

int main()
{
    char inp[80], x, p, dl[10], y, start = 'a';
    int i = 0, j, k, l, n, m, len;

    printf("Enter the input: ");
    scanf("%s", inp);

    len = strlen(inp);
    inp[len] = '$';
    inp[len+1] = '\0';

    push(stack, &top, start);

    printf("\nStack\t\tInput");
    printt(stack, &top, inp, i);

    do {
        x = inp[i];
        p = stacktop(stack);

        isproduct(x, p);

        if (strcmp(temp, "emp") == 0)
            error();

        if (strcmp(temp, "acc") == 0)
            break;

        if (temp[0] == 's')   // SHIFT
        {
            push(stack, &top, inp[i]);
            push(stack, &top, temp[1]);
            i++;
        }
        else if (temp[0] == 'r')   // REDUCE
        {
            j = isstate(temp[1]);

            strcpy(temp, rl[j-1].right);
            dl[0] = rl[j-1].left;
            dl[1] = '\0';

            n = strlen(temp);

            for (k = 0; k < 2*n; k++)
                pop(stack, &top);

            push(stack, &top, dl[0]);

            l = top;
            y = stack[l-1];

            isreduce(y, dl[0]);

            push(stack, &top, temp[0]);
        }

        printt(stack, &top, inp, i);

    } while (inp[i] != '\0');

    if (strcmp(temp, "acc") == 0)
        printf("\nAccepted input");
    else
        printf("\nInvalid input");

    return 0;
}

// Stack operations
void push(char *s, int *sp, char item)
{
    s[++(*sp)] = item;
}

char pop(char *s, int *sp)
{
    return s[(*sp)--];
}

char stacktop(char *s)
{
    return s[top];
}

// Table lookup
void isproduct(char x, char p)
{
    int k = ister(x);
    int l = isstate(p);
    strcpy(temp, A[l-1].row[k-1]);
}

void isreduce(char x, char p)
{
    int k = isstate(x);
    int l = isnter(p);
    strcpy(temp, G[k-1].r[l-1]);
}

// Helpers
int ister(char x)
{
    for (int i = 0; i < 6; i++)
        if (x == ter[i])
            return i+1;
    return 0;
}

int isnter(char x)
{
    for (int i = 0; i < 3; i++)
        if (x == nter[i])
            return i+1;
    return 0;
}

int isstate(char p)
{
    for (int i = 0; i < 12; i++)
        if (p == states[i])
            return i+1;
    return 0;
}

void error()
{
    printf("\nError in input");
    exit(0);
}

// Printing
void printt(char *t, int *p, char inp[], int i)
{
    int r;
    printf("\n");

    for (r = 0; r <= *p; r++)
        rep(t, r);

    printf("\t\t");

    for (r = i; inp[r] != '\0'; r++)
        printf("%c", inp[r]);
}

void rep(char t[], int r)
{
    printf("%c", t[r]);
}