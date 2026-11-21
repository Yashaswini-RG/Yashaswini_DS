
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;
struct Node *front = NULL;
struct Node *rear = NULL;

void push(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    struct Node *temp = top;
    printf("Popped element: %d\n", temp->data);

    top = top->next;
    free(temp);
}

void displayStack() {
    struct Node *temp = top;

    if (temp == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Queue Overflow!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue.\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void displayQueue() {
    struct Node *temp = front;

    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                while (1) {
                    printf("\n--- STACK MENU ---\n");
                    printf("1. Push\n");
                    printf("2. Pop\n");
                    printf("3. Display\n");
                    printf("4. Back to Main Menu\n");

                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    if (choice == 4)
                        break;

                    switch (choice) {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            push(value);
                            break;

                        case 2:
                            pop();
                            break;

                        case 3:
                            displayStack();
                            break;

                        default:
                            printf("Invalid choice!\n");
                    }
                }
                break;

            case 2:
                while (1) {
                    printf("\n--- QUEUE MENU ---\n");
                    printf("1. Enqueue\n");
                    printf("2. Dequeue\n");
                    printf("3. Display\n");
                    printf("4. Back to Main Menu\n");

                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    if (choice == 4)
                        break;

                    switch (choice) {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &value);
                            enqueue(value);
                            break;

                        case 2:
                            dequeue();
                            break;

                        case 3:
                            displayQueue();
                            break;

                        default:
                            printf("Invalid choice!\n");
                    }
                }
                break;

            case 3:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

