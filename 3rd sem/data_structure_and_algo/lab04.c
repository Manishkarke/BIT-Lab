// Lab 04: C program to implement Linear queue
#include "stdio.h"

#define MAX 100
// Linear Queue structure
typedef struct LinearQueue
{
    int data[MAX];
    int front;
    int rear;
} LinearQueue;

// function definations
int isEmpty(LinearQueue);
int isFull(LinearQueue);
void displayMenu();
void enqueue(LinearQueue *, int);
int dequeue(LinearQueue *);
int peek(LinearQueue);
void traverse(LinearQueue);

int main()
{
    LinearQueue q;
    int choice, data;

    do
    {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            q.front = -1;
            q.rear = -1;
            printf("\n Empty Linear queue is created successfully.\n");
            break;

        case 2:
            if (isEmpty(q))
                printf("true\n");
            else
                printf("false\n");
            break;

        case 3:
            if (isFull(q))
                printf("true\n");
            else
                printf("false\n");
            break;

        case 4:
            printf("\nEnter the data to store: ");
            scanf("%d", &data);
            enqueue(&q, data);
            break;

        case 5:
            printf("\nRemoved data is %d.\n", dequeue(&q));
            break;

        case 6:
            printf("\nData in the front is %d.", peek(q));
            break;

        case 7:
            traverse(q);
            break;

        case 8:
            printf("\nbye bye!!!!");
            break;
        default:
            printf("\nInvalid choice\n");
        }

    } while (choice != 8);

    return 0;
}

// Display Menu
void displayMenu()
{
    printf("\n\t\t\t Linear Queue Menu\n");
    printf("1. Create empty queue\n");
    printf("2. Is queue empty?\n");
    printf("3. Is queue full?\n");
    printf("4. Enqueue\n");
    printf("5. dequeue\n");
    printf("6. Peek\n");
    printf("7. Traverse\n");
    printf("8. Quit\n");
}

// Check if Queue is empty
int isEmpty(LinearQueue q)
{
    return (q.front == -1 || q.front > q.rear) ? 1 : 0;
}

// check if queue is full
int isFull(LinearQueue q)
{
    return (q.rear == MAX - 1) ? 1 : 0;
}

// Insert Element in Linear queue
void enqueue(LinearQueue * q, int data) {
    if(isFull(*q)) {
        printf("Queue is Full");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->data[++q->rear] = data;
        printf("Data inserted successfully.");
    }
}

// Remove element from the queue
int dequeue(LinearQueue* q) {
    if(isEmpty(*q)) {
        printf("Queue is Empty.");
    } else {
        int el = q->data[q->front++];
        if(q->front > q->rear) {
            q->front = -1;
            q->rear = -1;
        }
        return el;
    }
}

// Display element at front in the queue
int peek(LinearQueue q) {
    if (isEmpty(q))
    {
        printf("Queue is Empty");
    } else {
        return q.data[q.front];
    }
    
}

// Display all the element of the queue
void traverse(LinearQueue q) {
    if (isEmpty(q))
    {
        printf("Queue is Empty");
    } else {
        for(int i = q.front; i <= q.rear; i++) {
            printf("%d\t", q.data[i]);
        }
        printf("\n");
    }
}