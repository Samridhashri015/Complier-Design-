#include<stdio.h>
#include<string.h>

char stack[20];
char input[20];
int top = -1;
int i = 0;

void push(char x)
{
    stack[++top] = x;
}

void pop()
{
    top--;
}

int main()
{
    printf("Enter the input string: ");
    scanf("%s", input);

    push('$');
    push('E');   // Start symbol

    printf("\nStack\tInput\tAction\n");

    while(stack[top] != '$')
    {
        printf("%s\t%s\t", stack, &input[i]);

        if(stack[top] == input[i])
        {
            pop();
            i++;
            printf("Match %c\n", input[i-1]);
        }
        else
        {
            switch(stack[top])
            {
                case 'E':
                    pop();
                    push('A');
                    push('T');
                    printf("E->TA\n");
                    break;

                case 'A':
                    if(input[i] == '+')
                    {
                        pop();
                        push('A');
                        push('T');
                        push('+');
                        printf("A->+TA\n");
                    }
                    else
                    {
                        pop();
                        printf("A->ε\n");
                    }
                    break;

                case 'T':
                    pop();
                    push('B');
                    push('F');
                    printf("T->FB\n");
                    break;

                case 'B':
                    if(input[i] == '*')
                    {
                        pop();
                        push('B');
                        push('F');
                        push('*');
                        printf("B->*FB\n");
                    }
                    else
                    {
                        pop();
                        printf("B->ε\n");
                    }
                    break;

                case 'F':
                    if(input[i] == 'i')
                    {
                        pop();
                        push('i');
                        printf("F->i\n");
                    }
                    break;

                default:
                    printf("Error\n");
                    return 0;
            }
        }
    }

    if(input[i] == '$')
        printf("\nString Accepted\n");
    else
        printf("\nString Rejected\n");

    return 0;
}