// Lab 3: C program to evaluate the given postfix expression
#include "./headers/stack.h"
#include "stdlib.h"
#include "math.h"
#include "ctype.h"
#define SIZE 100

int evaluatePostfix(Stack *s, char postfix[SIZE]);
void scanValue(int *a, char ch);

int main()
{
    Stack vstack;
    createEmptyStack(&vstack);
    char postfix[SIZE];
    int result;
    printf("Enter a valid postfix expression with variables from 'a' to 'f': ");
    fgets(postfix, SIZE, stdin);

    result = evaluatePostfix(&vstack, postfix);

    printf("The result is %d", result);

    return 0;
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int evaluatePostfix(Stack *s, char postfix[SIZE])
{
    int a, b, c, d, e, f, operand1, operand2;
    char ch;
    scanValue(&a, 'a');
    scanValue(&b, 'b');
    scanValue(&c, 'c');
    scanValue(&d, 'd');
    scanValue(&e, 'e');
    scanValue(&f, 'f');
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if (isOperator(ch))
        {
            operand2 = pop(s);
            operand1 = pop(s);

            switch (ch)
            {
            case '+':
                push(s, operand1 + operand2);
                break;
            case '-':
                push(s, operand1 - operand2);
                break;
            case '*':
                push(s, operand1 * operand2);
                break;
            case '/':
                if (operand2 == 0)
                {
                    printf("Division by 0 is invalid.");
                    return -1;
                }
                push(s, operand1 / operand2);
                break;
            case '^':
                push(s, pow(operand1, operand2));
                break;
            default:
                printf("Invalid operator.");
                return -1;
            }
        }
        else if(isalnum(ch))
        {
            switch (ch)
            {
            case 'a':
                push(s, a);
                break;
            case 'b':
                push(s, b);
                break;
            case 'c':
                push(s, c);
                break;
            case 'd':
                push(s, d);
                break;
            case 'e':
                push(s, e);
                break;
            case 'f':
                push(s, f);
                break;
            default:
                printf("Invalid character.");
                return -1;
            }
        }
    }

    return pop(s);
}

void scanValue(int *a, char ch)
{
    printf("Please enter value for '%c': ", ch);
    scanf("%d", a);
}