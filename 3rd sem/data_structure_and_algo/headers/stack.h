#include "stdio.h"
#define MAX 50

typedef struct Stack
{
    int data[MAX];
    int top;
} Stack;

void createEmptyStack(Stack *s);
int isFull(Stack s);
int isEmpty(Stack s);
void push(Stack *s, int da);
int pop(Stack *s);

// create an empty stack
void createEmptyStack(Stack *s)
{
    s->top = -1;
    printf("New stack is successfully created.\n\n");
}

// Insert data in stack
void push(Stack *s, int data)
{
    if (isFull(*s))
    {
        printf("Stack overflow. \n");
    }
    else
    {
        s->data[++s->top] = data;
    }
}

// delete data from stack
int pop(Stack *s)
{
    if (isEmpty(*s))
    {
        printf("Stack underflow.\n");
        return -1;
    }
    else
    {
        return s->data[s->top--];
    }
}

// check if the stack is Empty
int isEmpty(Stack s)
{
    return (s.top == -1) ? 1 : 0;
}

// Check if the stack is full
int isFull(Stack s)
{
    return (s.top == MAX - 1) ? 1 : 0;
}