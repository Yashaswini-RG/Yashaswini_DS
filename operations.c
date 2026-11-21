
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a linked list
struct Node* createList() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return head;
        }

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    return head;
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Function to sort the linked list
void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    if (head == NULL)
        return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("Linked list sorted successfully.\n");
}

// Function to reverse the linked list
struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    printf("Linked list reversed successfully.\n");

    return prev;
}

// Function to concatenate two linked lists
struct Node* concatenate(struct Node *head1,
                         struct Node *head2) {
    struct Node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    printf("Linked lists concatenated successfully.\n");

    return head1;
}

// Main function
int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int choice;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Create First Linked List\n");
        printf("2. Create Second Linked List\n");
        printf("3. Display First Linked List\n");
        printf("4. Sort Linked List\n");
        printf("5. Reverse Linked List\n");
        printf("6. Concatenate Two Linked Lists\n");
        printf("7. Display Second Linked List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head1 = createList();
                break;

            case 2:
                head2 = createList();
                break;

            case 3:
                display(head1);
                break;

            case 4:
                sortList(head1);
                display(head1);
                break;

            case 5:
                head1 = reverseList(head1);
                display(head1);
                break;

            case 6:
                head1 = concatenate(head1, head2);
                head2 = NULL;
                display(head1);
                break;

            case 7:
                display(head2);
                break;

            case 8:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

