#include <stdio.h>
#include <stdlib.h>

#define N 5   // Queue size

int queue[N];
int front = -1;
int rear = -1;

// Function to insert element (enqueue)
void enqueue(int x) {
    if (rear == N - 1) {
        printf("\nQueue Overflow!\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
        printf("%d inserted into the queue.\n", x);
    } else {
        rear++;
        queue[rear] = x;
        printf("%d inserted into the queue.\n", x);
    }
}

// Function to delete element (dequeue)
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("\nQueue Underflow! Queue is empty.\n");
    } else if (front == rear) {
        printf("%d deleted from the queue.\n", queue[front]);
        front = rear = -1;  // Reset when empty
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;
    }
}

// Function to display the queue
void display() {
    int i;
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements are: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

)
void peek() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nFront element is: %d\n", queue[front]);
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting program... Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

