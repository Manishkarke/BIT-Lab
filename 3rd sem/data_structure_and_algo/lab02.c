// Lab 02: C program to convert infix expression to post-fix expression
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For isalnum()

#define MAX 100

typedef struct Stack {
    char data[MAX];
    int top;
} Stack;

void createEmptyStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack s) {
    return s.top == MAX - 1;
}

int isEmpty(Stack s) {
    return s.top == -1;
}

void push(Stack *s, char data) {
    if (isFull(*s)) {
        printf("Stack overflow\n");
        exit(1);  // Terminate program on error
    }
    s->data[++s->top] = data;
}

char pop(Stack *s) {
    if (isEmpty(*s)) {
        printf("Stack underflow\n");
        exit(1);  // Terminate program on error
    }
    return s->data[s->top--];
}

int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;  // Treat other characters as operands (lower precedence)
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char *infix, char *postfix) {
    Stack opstack;
    createEmptyStack(&opstack);

    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; ++i) {
        ch = infix[i];

        if (isspace(ch)) {  // Ignore spaces
            continue;
        } else if (isalnum(ch)) {  // Check if operand (alphanumeric)
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&opstack, ch);
        } else if (ch == ')') {
            while ((ch = pop(&opstack)) != '(' && !isEmpty(opstack)) {
                postfix[j++] = ch;
            }
            if (ch != '(') {
                printf("Invalid infix Expression: Mismatched parentheses\n");
                exit(1);  // Terminate program on error
            }
        } else if (isOperator(ch)) {
            while (!isEmpty(opstack) && precedence(opstack.data[opstack.top]) >= precedence(ch)) {
                postfix[j++] = pop(&opstack);
            }
            push(&opstack, ch);
        } else {
            printf("Invalid infix Expression: Unknown character '%c'\n", ch);
            exit(1);
        }
    }

    while (!isEmpty(opstack)) {
        postfix[j++] = pop(&opstack);
    }

    postfix[j] = '\0'; // Null terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid infix expression: ");
    fgets(infix, MAX, stdin);  // Read entire line, including spaces

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
