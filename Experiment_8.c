#include <stdio.h>
#include <string.h>
#include <ctype.h>

char productions[10][20];
char leading[10][10], trailing[10][10];
int n;

// function to find LEADING
void findLeading(int i, int j)
{
    if (!isupper(productions[i][j])) // terminal
    {
        int k;
        for (k = 0; k < strlen(leading[i]); k++)
            if (leading[i][k] == productions[i][j])
                return;

        int len = strlen(leading[i]);
        leading[i][len] = productions[i][j];
        leading[i][len + 1] = '\0';
    }
    else
    {
        int k;
        for (k = 0; k < n; k++)
        {
            if (productions[k][0] == productions[i][j])
            {
                findLeading(k, 2);
            }
        }
    }
}

// function to find TRAILING
void findTrailing(int i, int j)
{
    if (!isupper(productions[i][j])) // terminal
    {
        int k;
        for (k = 0; k < strlen(trailing[i]); k++)
            if (trailing[i][k] == productions[i][j])
                return;

        int len = strlen(trailing[i]);
        trailing[i][len] = productions[i][j];
        trailing[i][len + 1] = '\0';
    }
    else
    {
        int k;
        for (k = 0; k < n; k++)
        {
            if (productions[k][0] == productions[i][j])
            {
                findTrailing(k, strlen(productions[k]) - 1);
            }
        }
    }
}

int main()
{
    int i;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E=E+T):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", productions[i]);
        leading[i][0] = '\0';
        trailing[i][0] = '\0';
    }

    // compute LEADING
    for (i = 0; i < n; i++)
    {
        findLeading(i, 2);
    }

    // compute TRAILING
    for (i = 0; i < n; i++)
    {
        findTrailing(i, strlen(productions[i]) - 1);
    }

    // display LEADING
    printf("\nLEADING:\n");
    for (i = 0; i < n; i++)
    {
        printf("%c : { %s }\n", productions[i][0], leading[i]);
    }

    // display TRAILING
    printf("\nTRAILING:\n");
    for (i = 0; i < n; i++)
    {
        printf("%c : { %s }\n", productions[i][0], trailing[i]);
    }

    return 0;
}