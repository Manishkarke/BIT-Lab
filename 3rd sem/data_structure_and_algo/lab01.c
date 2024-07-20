// Lab 01: C program with stack implementation
#include "stdio.h"
#define MAX 20
// stack structure
typedef struct Stack
{
    int data[MAX];
    int top;

} Stack;

// Stack operation definations
void createEmptyStack(Stack *s);
int isFull(Stack s);
int isEmpty(Stack s);
void push(Stack *s);
int pop(Stack *s);
void peek(Stack s);
void display(Stack s);

int displayMenu()
{
    int choice;
    printf("\n\t\t\tStack Menu\n");
    printf("1. create an empty stack\n");
    printf("2. insert data in stack\n");
    printf("3. delete data from stack\n");
    printf("4. check if stack is empty\n");
    printf("5. check if stack is full\n");
    printf("6. display data on top of stack\n");
    printf("7. display all the element in stack\n");
    printf("8. exit program\n");

    printf("\nyour choice: ");
    scanf("%d", &choice);

    return choice;
}

int main()
{
    Stack stk;
    int choice;
    do
    {
        choice = displayMenu();
        switch (choice)
        {
        case 1:
            createEmptyStack(&stk);
            break;

        case 2:
            push(&stk);
            break;

        case 3:
            printf("Deleted data is %d", pop(&stk));
            break;

        case 4:
            if (isEmpty(stk))
            {
                printf("true");
            }
            else
            {
                printf("false");
            }
            break;

        case 5:
            if (isFull(stk))
            {
                printf("true");
            }
            else
            {
                printf("false");
            }
            break;

        case 6:
            peek(stk);
            break;

        case 7:
            display(stk);
            break;

        case 8:
            break;

        default:
            printf("invalid choice");
        }
    } while (choice != 8 && choice <= 8 && choice >= 1);
    return 0;
}

// create an empty stack
void createEmptyStack(Stack *s)
{
    s->top = -1;
    printf("New stack is successfully created.");
}

// Insert data in stack
void push(Stack *s)
{
    if (isFull(*s))
    {
        printf("Stack overflow. \n");
    }
    else
    {
        printf("Enter your data: ");
        scanf("%d", &s->data[++s->top]);
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

// Take a peek at top of the stack
void peek(Stack s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow.");
    }
    else
    {
        printf("stack[top] : %d ", s.data[s.top]);
    }
}

// Display all the element of the stack.
void display(Stack s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow.");
    }
    else
    {
        int i = s.top;

        while (i != -1)
        {
            printf("|         |\n");
            if (s.data[i] < 10)
                printf("|    %d    |\n", s.data[i--]);
            else if (s.data[i] > 99)
            {
                printf("|   %d   |\n", s.data[i--]);
            }
            else
            {
                printf("|    %d   |\n", s.data[i--]);
            }
            printf("|_________|\n");
        }
    }
}