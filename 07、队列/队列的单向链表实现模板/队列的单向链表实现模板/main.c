#include <stdio.h>
#include <stdlib.h>

#define eleType int

typedef struct Node {
    eleType data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    size_t size;
} Queue;

void QueueCreate(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

void QueueDestroy(Queue* q) {
    while (q->front) {
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
    q->size = 0;
}

void QueuePush(Queue* q, eleType element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

eleType QueuePop(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        exit(1);
    }

    eleType element = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    if (q->size == 0) {
        q->rear = NULL;
    }
    return element;
}

eleType QueueFront(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return q->front->data;
}

size_t QueueSize(Queue* q) {
    return q->size;
}

int main() {
    Queue q;
    QueueCreate(&q);
    QueuePush(&q, 10);
    QueuePush(&q, 20);
    QueuePush(&q, 30);
    printf("出队元素: %d\n", QueuePop(&q));
    printf("队头元素: %d\n", QueueFront(&q));
    printf("队列大小: %zu\n", QueueSize(&q));
    QueueDestroy(&q);

    return 0;
}