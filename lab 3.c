#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void insert(int item) {

    if (rear == MAX - 1) {
        printf("\nQueue Overflow!\n");
    } else {

        if (front == -1){
            front = 0;
        }

           rear=rear+1;
           queue[rear]=item;

           printf("The item %d is inserted\n",item);
        }

    }

int delete() {
int item;
if(front==-1||front>rear){
    printf("Queue is empty");
}
else{
    item=queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=front+1;
    }
    printf("The item is deleted %d\n",item);
}
}


void display() {
    int i;

    if (front == -1||front>rear) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements are:\n");

        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main() {
    int choice,x;

    while (1) {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be added :");
                scanf("%d",&x);
                insert(x);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("End of the program\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

