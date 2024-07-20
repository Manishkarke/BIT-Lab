// Lab05: C program to implemented circular queue
#include "stdio.h"
#define MAX 100
// Linear Queue structure
typedef struct CircularQueue
{
    int data[MAX];
    int front;
    int rear;
} CircularQueue;

// function definations
int isEmpty(CircularQueue);
int isFull(CircularQueue);
void displayMenu();
void enqueue(CircularQueue *, int);
int dequeue(CircularQueue *);
int peek(CircularQueue);
void traverse(CircularQueue);

int main()
{
    CircularQueue q;
    int choice, data;
    q.front = q.rear = -1;

    do
    {
        choice = -1;
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            q.front = -1;
            q.rear = -1;
            printf("Empty Circular queue is created successfully.");
            break;

        case 2:
            if (isEmpty(q))
                printf("true");
            else
                printf("false");
            break;

        case 3:
            if (isFull(q))
                printf("true");
            else
                printf("false");
            break;

        case 4:
            printf("Enter the data to store: ");
            scanf("%d", &data);
            enqueue(&q, data);
            break;

        case 5:
            printf("Removed data is %d.", dequeue(&q));
            break;

        case 6:
            printf("Data in the front is %d.", peek(q));
            break;

        case 7:
            traverse(q);
            break;

        case 8:
            printf("bye bye!!!!");
            break;
        default:
            printf("Invalid choice");
        }

    } while (choice != 8);

    return 0;
}

// Display Menu
void displayMenu()
{
    printf("\n\n\t\t\t Circular Queue Menu\n");
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
int isEmpty(CircularQueue q)
{
    return (q.front == -1) ? 1 : 0;
}

// check if queue is full
int isFull(CircularQueue q)
{
    return (((q.rear + 1) % MAX) == q.front) ? 1 : 0;
}

// Insert Element in Circular queue
void enqueue(CircularQueue *q, int data)
{
    if (isFull(*q))
    {
        printf("Queue is Full");
    }
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = data;
        printf("Data inserted successfully.");
    }
}

// Remove element from the queue
int dequeue(CircularQueue *q)
{
    if (isEmpty(*q))
    {
        printf("Queue is Empty.");
    }
    else
    {
        int el = q->data[q->front];
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % MAX;
        }
        return el;
    }
}

// Display element at front in the queue
int peek(CircularQueue q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty");
    }
    else
    {
        return q.data[q.front];
    }
}

// Display all the element of the queue
void traverse(CircularQueue q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty");
    }
    else
    {
        int i = q.front;
        while (i != q.rear)
        {
            printf("%d\t", q.data[i]);
            i = (i + 1) % MAX;
        }
        printf("%d", q.data[i]);
    }
}