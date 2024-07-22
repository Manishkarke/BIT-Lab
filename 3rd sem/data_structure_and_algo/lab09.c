// Lab 09: C program to implement doubly linked list
#include "stdio.h"
#include "stdlib.h"
// ------------------------------ Data Structure
// ---------------------------------- //
typedef struct DoublyList {
  int data;
  struct DoublyList *prev;
  struct DoublyList *next;
} DoublyList;

// ------------------------------ Function Declaration
// ---------------------------------- //
DoublyList *createNode(int);

// Functions to Display Menu
void mainMenu();
void insertMenu();
void deleteMenu();
void displayMenu();

// Utility Functions
int length(DoublyList *);
int isEmpty(DoublyList *);
void clearScreen();
void wait();

// search Node
DoublyList *searchNode(DoublyList *, int);

// Display Functions
int nodeAtPosition(DoublyList *, int);
void displayAllNodes(DoublyList *);

// Insertion Function
void insertAtBeginning(DoublyList **, int);
void insertAtEnd(DoublyList **, int);
void insertAtPosition(DoublyList **, int, int);
void insertAfterNode(DoublyList **, int, int);

// Deletion Function
int deleteAtBeginning(DoublyList **);
int deleteAtEnd(DoublyList **);
int deleteAtPosition(DoublyList **, int);
int deleteAfterNode(DoublyList **, int);

// ------------------------------ Main Function
// ---------------------------------- //
int main() {
  int choice, ele;
  DoublyList *head = NULL;
  while (1) {
    clearScreen();
    mainMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // for Exiting the menu
    if (choice == 7) {
      printf("Thank You!!!\nBye bye!");
      break;
    }

    switch (choice) {
    // For Insert Operation
    case 1:
      do {
        clearScreen();
        insertMenu();
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
          clearScreen();
          break;
        }

        printf("\nEnter your Element: ");
        scanf("%d", &ele);
        switch (choice) {
        // For Insertion In the beginning
        case 1:
          insertAtBeginning(&head, ele);
          break;

        // For Insertion at the end
        case 2:
          insertAtEnd(&head, ele);
          break;

        // For Insertion at a position;
        case 3:
          int pos;
          printf("Enter the position you want to insert at: ");
          scanf("%d", &pos);
          insertAtPosition(&head, ele, pos);
          break;

        // For Insertion at node after given node
        case 4:
          int nodeData;
          printf("Enter the node after which you want to store: ");
          scanf("%d", &nodeData);
          insertAfterNode(&head, ele, nodeData);
          break;

        default:
          printf("Invalid Choice!!!");
        }

        if (choice != 5)
          wait();
      } while (choice != 5);
      break;

    // For Delete operation
    case 2:
      do {
        clearScreen();
        deleteMenu();
        int choice;
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        // Back to main menu
        if (choice == 5)
          break;
        if (head == NULL) {
          printf("List is empty.");
          break;
        }
        switch (choice) {
        // For Deletion In the beginning
        case 1:
          printf("Deleted data is %d", deleteAtBeginning(&head));
          break;

        // For Deletion at the end
        case 2:
          printf("Deleted data is %d.", deleteAtEnd(&head));
          break;

        // For Deletion at a position;
        case 3:
          int pos;
          printf("Enter the position of which you want to delete node: ");
          scanf("%d", &pos);

          printf("Deleted data is %d.", deleteAtPosition(&head, pos));
          break;

        // For Deletion at node after given node
        case 4:
          printf("Enter the node of which after node you want to delete: ");
          scanf("%d", &ele);

          printf("Deleted data is %d.", deleteAfterNode(&head, ele));
          break;

        default:
          printf("Invalid Choice!!!\n");
        }
        if (choice != 5)
          wait();
      } while (choice != 5);
      break;

    // For checking if the list is empty
    case 3:
      if (isEmpty(head))
        printf("The list is empty.");
      else
        printf("List is not empty.");
      break;

    // for Getting the length of the list
    case 4:
      printf("Length of the list: %d", length(head));
      break;

    // for search of node operation
    case 5:
      if (isEmpty(head)) {
        printf("List is empty.");
        break;
      } else {
        printf("Enter the node you want to search for: ");
        scanf("%d", &ele);
        if (searchNode(head, ele)) {
          printf("Element exists in the list.");
        } else {
          printf("Element doesn't exists in the list.");
        }
      }
      break;

    // For display node menu
    case 6:
      do {
        clearScreen();
        displayMenu();
        int choice;
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        if (choice == 3)
          break;

        switch (choice) {
        // Display node at particular position
        case 1:
          int pos;
          printf("Enter the position: ");
          scanf("%d", &pos);
          printf("The node at position %d is %d.", pos,
                 nodeAtPosition(head, pos));
          break;

        // Display All nodes
        case 2:
          displayAllNodes(head);
          break;

        default:
          printf("Invalid Choice!!!");
        }
        if (choice != 3)
          wait();
      } while (choice != 3);
      break;

    default:
      clearScreen();
      printf("Invalid Choice.");
    }

    wait();
  }
}

// ------------------------------ Menu Function
// ---------------------------------- //
// ----------- Main Menu Function
void mainMenu() {
  printf("\t\tMain Menu Of Doubly Linked List\n");
  printf("1. Insert Node\n");
  printf("2. Delete Node\n");
  printf("3. Is list empty?\n");
  printf("4. Length of the list\n");
  printf("5. Search for node\n");
  printf("6. Display node\n");
  printf("7. Exit program\n");
}

// ----------- Insert Menu Function
void insertMenu() {
  printf("\t\t Insertion Menu\n");
  printf("1. At the begining of list\n");
  printf("2. At the end of the list\n");
  printf("3. At a position in the list\n");
  printf("4. After a given node in the list\n");
  printf("5. Back to main menu\n");
}

// ----------- Deletion Menu Function
void deleteMenu() {
  printf("\t\t Deletion Menu\n");
  printf("1. At the begining of list\n");
  printf("2. At the end of the list\n");
  printf("3. At a position in the list\n");
  printf("4. After a given node in the list\n");
  printf("5. Back to main menu\n");
}

// ----------- Display Node Menu Function
void displayMenu() {
  printf("\t\t Display Node Menu\n");
  printf("1. Node at position\n");
  printf("2. All nodes\n");
  printf("3. Back to main menu\n");
}

// ------------------------------ Create Node Function
// ---------------------------------- //
DoublyList *createNode(int val) {
  DoublyList *newNode = (DoublyList *)malloc(sizeof(DoublyList));
  newNode->data = val;
  newNode->next = newNode->prev = NULL;

  return newNode;
}

// ------------------------------ Utility Function
// ---------------------------------- //
// --------- isEmpty function
int isEmpty(DoublyList *head) { return head == NULL ? 1 : 0; }

// --------- length Function
int length(DoublyList *head) {
  if (isEmpty(head))
    return 0;
  else {
    int count = 1;
    DoublyList *current = head;
    while (current->next != NULL) {
      current = current->next;
      count += 1;
    }
    return count;
  }
}

// --------- Clear Screen Function
void clearScreen() { printf("\033[H\033[J"); }

// --------- Wait for user response Function
void wait() {
  printf("\nPress Enter to continue...");
  getchar();
  getchar();
}

// ------------------------------ Search Functions
// ---------------------------------- //
DoublyList *searchNode(DoublyList *head, int data) {
  DoublyList *current = head;
  do {
    if (current->data == data)
      return current;
    current = current->next;
  } while (current != NULL);

  return NULL;
}

// ------------------------------ Insertion Functions
// ---------------------------------- //
// ----------- At Beginning
void insertAtBeginning(DoublyList **head, int ele) {
  DoublyList *newNode = createNode(ele);
  if (isEmpty(*head)) {
    *head = newNode;
  } else {
    (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
  }
  printf("Data inserted successfully.");
}

// ----------- At End
void insertAtEnd(DoublyList **head, int ele) {
  DoublyList *newNode = createNode(ele);
  if (isEmpty(*head))
    *head = newNode;
  else {
    DoublyList *current = *head;
    while (current->next != NULL)
      current = current->next;

    newNode->prev = current;
    current->next = newNode;
  }
  printf("Data inserted successfully at the end.");
}

// ----------- At Position
void insertAtPosition(DoublyList **head, int ele, int pos) {
  DoublyList *newNode = createNode(ele);
  if (pos > length(*head) + 1) {
    char ch;
    printf("The Position is greater than the length of list.\nDo you want to "
           "put the node at the end of list?(y/n)\n");
    scanf(" %c", &ch);

    if (ch == 'y') {
      insertAtEnd(head, ele);
    } else {
      printf("Insertion Failed.");
    }
  } else if (pos == 1) {
    insertAtBeginning(head, ele);
  } else {
    DoublyList *current = *head;
    for (int i = 1; i < pos - 1; i++) {
      current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
      current->next->prev = newNode;
    }
    current->next = newNode;
  }

  printf("Data inserted successfully at the position %d.", pos);
}

// ----------- After the given node
void insertAfterNode(DoublyList **head, int ele, int data) {
  DoublyList *newNode = createNode(ele);
  DoublyList *current = searchNode(*head, data); // Use 'data' here, not 'ele'

  if (current == NULL) {
    char ch;
    printf("The node with data %d was not found in the list.\nDo you want to "
           "put the node at the end of the list?(y/n)\n",
           data);
    scanf(" %c", &ch);

    if (ch == 'y') {
      insertAtEnd(head, ele);
    } else {
      printf("Insertion Failed.");
    }
  } else {
    newNode->next = current->next;
    if (current->next != NULL) {
      current->next->prev = newNode;
    }
    newNode->prev = current;
    current->next = newNode;
    printf("Data inserted successfully after node with data %d.", data);
  }
}

// ------------------------------ Deletetion of node Functions
// ---------------------------------- //
// ----------- At Beginning
int deleteAtBeginning(DoublyList **head) {
  int el = (*head)->data;
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
  } else {
    DoublyList *current = *head;
    *head = current->next;
    (*head)->prev = NULL;
    free(current);
  }
  return el;
}

// ----------- At End
int deleteAtEnd(DoublyList **head) {
  int el;
  if ((*head)->next == NULL) {
    el = (*head)->data;
    free(*head);
    (*head) = NULL;
  } else {
    DoublyList *current = *head;

    while (current->next != NULL) {
      current = current->next;
    }

    el = current->data;
    current->prev->next = NULL;
    free(current);
  }
  return el;
}

// ----------- At a position
int deleteAtPosition(DoublyList **head, int pos) {
  int el;
  if (pos > length(*head)) {
    printf("Our list is only of %d nodes.", length(*head));
    exit(1);
  } else if (pos == 1) {
    el = deleteAtBeginning(head);
  } else {
    DoublyList *current = *head;
    for (int i = 1; i < pos; i++) {
      current = current->next;
    }
    el = current->data;
    current->prev->next = current->next;
    if (current->next != NULL) {
      current->next->prev = current->prev;
    }
    free(current);
  }
  return el;
}

// ----------- After a given node
int deleteAfterNode(DoublyList **head, int data) {
  DoublyList *current = searchNode(*head, data); // Use 'data' here, not 'ele'
  int el;
  if (current == NULL) {
    printf("Node doesn't exist.");
    exit(1);
  } else {
    current = current->next;

    el = current->data;

    current->prev->next = current->next;
    if (current->next != NULL) {
      current->next->prev = current->prev;
    }
    free(current);
  }

  return el;
}

// ------------------------------ Display Functions
// ---------------------------------- //

// ----------- Display A single node at position
int nodeAtPosition(DoublyList *head, int pos) {
  int el;
  if (pos > length(head)) {
    printf("Our list is only of %d nodes.", length(head));
    exit(1);
  } else if (pos == 1) {
    el = head->data;
  } else {
    DoublyList *current = head;
    for (int i = 1; i < pos; i++) {
      current = current->next;
    }
    el = current->data;
  }
  return el;
}

// ----------- Display All Node function
void displayAllNodes(DoublyList *head) {
  if (isEmpty(head))
    printf("List is empty.");
  else {
    DoublyList *current = head;
    while (current->next != NULL) {
      printf("%d -> ", current->data);
      current = current->next;
    }
    printf("%d", current->data);
  }
}