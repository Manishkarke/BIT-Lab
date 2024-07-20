#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function prototypes for linked list operations
struct Node *createNode(int data);
void insertAtBeginning(struct Node **head_ref, int new_data);
void insertAtEnd(struct Node **head_ref, int new_data);
void insertAtPosition(struct Node **head_ref, int new_data, int position);
void insertAfter(struct Node *prev_node, int new_data);
void deleteAtBeginning(struct Node **head_ref);
void deleteAtEnd(struct Node **head_ref);
void deleteAtPosition(struct Node **head_ref, int position);
void deleteAfter(struct Node *prev_node);
void display(struct Node *head);
// **Declare the searchNode function prototype here**
struct Node *searchNode(struct Node *head, int value);

int main()
{
    struct Node *head = NULL; // Initially empty list

    int choice, data, position;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Insert after a node\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from end\n");
        printf("7. Delete at position\n");
        printf("8. Delete after a node\n");
        printf("9. display the list\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position (starting from 1): ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;
        case 4:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter the value of the node after which to insert: ");
            int prev_value;
            scanf("%d", &prev_value);
            struct Node *prev_node = searchNode(head, prev_value); // Helper function for searching
            if (prev_node != NULL)
            {
                insertAfter(prev_node, data);
            }
            else
            {
                printf("Node with value %d not found.\n", prev_value);
            }
            break;
        case 5:
            deleteAtBeginning(&head);
            break;
        case 6:
            deleteAtEnd(&head);
            break;
        case 7:
            printf("Enter position to delete (starting from 1): ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        case 8:
            printf("Enter the value of the node before which to delete: ");
            scanf("%d", &prev_value);
            prev_node = searchNode(head, prev_value);
            if (prev_node != NULL && prev_node->next != NULL)
            { // Check for non-empty list and next node
                deleteAfter(prev_node);
            }
            else
            {
                printf("Invalid node or empty list.\n");
            }
            break;
        case 9:
            display(head);
            break;
        case 10:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insertion functions
void insertAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *newNode = createNode(new_data);
    if (head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }

    newNode->next = *head_ref;
    *head_ref = newNode;
}
void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *newNode = createNode(new_data);

    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }

    struct Node *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

void insertAtPosition(struct Node **head_ref, int new_data, int position)
{
    if (position < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = createNode(new_data);

    if (position == 1)
    {
        insertAtBeginning(head_ref, new_data);
        return;
    }

    struct Node *prev = *head_ref;
    int cnt = 1;
    while (prev != NULL && cnt < position - 1)
    {
        prev = prev->next;
        cnt++;
    }

    if (prev == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = prev->next;
    prev->next = newNode;
}

void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node *newNode = createNode(new_data);
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}

// Deletion functions

void deleteAtBeginning(struct Node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void deleteAtEnd(struct Node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if ((*head_ref)->next == NULL)
    {
        deleteAtBeginning(head_ref);
        return;
    }

    struct Node *last = *head_ref;
    while (last->next->next != NULL)
    {
        last = last->next;
    }
    free(last->next);
    last->next = NULL;
}

void deleteAtPosition(struct Node **head_ref, int position)
{
    if (position < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1)
    {
        deleteAtBeginning(head_ref);
        return;
    }

    struct Node *current = *head_ref;
    struct Node *prev = NULL;
    int cnt = 2;
    while (current != NULL && cnt < position)
    {
        current = current->next;
        cnt++;
    }

    if (current == NULL || current->next == NULL)
    {
        printf("Invalid position.\n");
        return;
    }
    prev = current;
    current = current->next;
    prev->next = current->next;
    free(current);
}

void deleteAfter(struct Node *prev_node)
{
    if (prev_node == NULL || prev_node->next == NULL)
    {
        printf("Invalid operation.\n");
        return;
    }

    struct Node *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Traversal function
void display(struct Node *head)
{
    printf("Linked list: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Helper function for searching (used in insertAfter and deleteAfter)
struct Node *searchNode(struct Node *head, int value)
{
    while (head != NULL && head->data != value)
    {
        head = head->next;
    }
    return head;
}