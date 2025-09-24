#include <stdio.h>
#include <stdlib.h>
#define MS 5

typedef struct {
    int arr[MS];
    int rear, front;
} FIFOQ;

// Initialize
void init(FIFOQ *ptq) {
    ptq->rear = -1;
    ptq->front = -1;
}

// Check if full
int isFull(FIFOQ *ptq) {
    return ((ptq->rear == MS - 1 && ptq->front == 0) || (ptq->rear + 1 == ptq->front));
}

// Check if empty
int isEmpty(FIFOQ *ptq) {
    return (ptq->front == -1);
}

// Peek
int peek(FIFOQ *ptq) {
    if (isEmpty(ptq))
        return -9999;
    return ptq->arr[ptq->front];
}

// FIFO Enqueue
void enqueue(FIFOQ *ptq, int item) {
    if (isFull(ptq)) {
        printf("Queue is FULL!\n");
        return;
    }

    if (ptq->front == -1)
        ptq->front = ptq->rear = 0;
    else if (ptq->rear == MS - 1)
        ptq->rear = 0;
    else
        ptq->rear++;

    ptq->arr[ptq->rear] = item;
}

// FIFO Dequeue
int dequeue(FIFOQ *ptq) {
    if (isEmpty(ptq))
        return -9999;

    int temp = ptq->arr[ptq->front];

    if (ptq->rear == ptq->front)
        ptq->rear = ptq->front = -1;
    else if (ptq->front == MS - 1)
        ptq->front = 0;
    else
        ptq->front++;

    return temp;
}

// Enqueue at front (DEQUE)
void enqueueFront(FIFOQ *ptq, int item) {
    if (isFull(ptq)) {
        printf("Queue is FULL!\n");
        return;
    }

    if (ptq->rear == -1)
        ptq->rear = ptq->front = 0;
    else if (ptq->front == 0)
        ptq->front = MS - 1;
    else
        ptq->front--;

    ptq->arr[ptq->front] = item;
}

// Dequeue from rear (DEQUE)
int dequeueRear(FIFOQ *ptq) {
    if (isEmpty(ptq))
        return -9999;

    int item = ptq->arr[ptq->rear];

    if (ptq->rear == ptq->front)
        ptq->rear = ptq->front = -1;
    else if (ptq->rear == 0)
        ptq->rear = MS - 1;
    else
        ptq->rear--;

    return item;
}

// Display queue
void display(FIFOQ *ptq) {
    if (isEmpty(ptq)) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue elements: ");
    int i = ptq->front;
    while (1) {
        printf("%d ", ptq->arr[i]);
        if (i == ptq->rear)
            break;
        i = (i + 1) % MS;
    }
    printf("\n");
}

// Main Menu
int main() {
    FIFOQ q;
    init(&q);

    int choice, item;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Enqueue (FIFO)\n");
        printf("2. Dequeue (FIFO)\n");
        printf("3. Peek (FIFO)\n");
        printf("4. Enqueue Front (DEQUE)\n");
        printf("5. Dequeue Rear (DEQUE)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;

            case 2:
                item = dequeue(&q);
                if (item == -9999)
                    printf("Queue is EMPTY!\n");
                else
                    printf("Dequeued: %d\n", item);
                break;

            case 3:
                item = peek(&q);
                if (item == -9999)
                    printf("Queue is EMPTY!\n");
                else
                    printf("Front element: %d\n", item);
                break;

            case 4:
                printf("Enter item to enqueue at front: ");
                scanf("%d", &item);
                enqueueFront(&q, item);
                break;

            case 5:
                item = dequeueRear(&q);
                if (item == -9999)
                    printf("Queue is EMPTY!\n");
                else
                    printf("Rear Dequeued: %d\n", item);
                break;

            case 6:
                display(&q);
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}