#include <stdio.h>
#include <stdlib.h>

#define eleType int

typedef struct {
    eleType* elements;
    size_t front;
    size_t rear;
    size_t capacity;
} Queue;

void QueueCreate(Queue* q) {
    q->elements = (eleType*)malloc(sizeof(eleType) * 8);
    q->front = 0;
    q->rear = 0;
    q->capacity = 8;
}

void QueueDestroy(Queue* q) {
    free(q->elements);
    q->front = 0;
    q->rear = 0;
    q->capacity = 0;
    q->elements = NULL;
}

void QueueResize(Queue* q) {
    eleType* newElements = (eleType*)realloc(q->elements, sizeof(eleType) * (q->capacity * 2));
    if (newElements == NULL) {
        exit(1);
    }
    q->elements = newElements;
    q->capacity *= 2;
}

void QueuePush(Queue* q, eleType element) {
    if (q->rear == q->capacity) {
        QueueResize(q);
    }
    q->elements[q->rear++] = element;
}

eleType QueuePop(Queue* q) {
    if (q->front == q->rear) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return q->elements[q->front++];
}

eleType QueueFront(Queue* q) {
    if (q->front == q->rear) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return q->elements[q->front];
}

size_t QueueSize(Queue* q) {
    return q->rear - q->front;
}

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    QueueCreate(&obj->q1);
    QueueCreate(&obj->q2);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    QueuePush(&obj->q1, x);
}

int myStackPop(MyStack* obj) {
    while (QueueSize(&obj->q1) > 1) {
        QueuePush(&obj->q2, QueuePop(&obj->q1));
    }
    int result = QueuePop(&obj->q1);
    while (QueueSize(&obj->q2) > 0) {
        QueuePush(&obj->q1, QueuePop(&obj->q2));
    }
    return result;
}

int myStackTop(MyStack* obj) {
    while (QueueSize(&obj->q1) > 1) {
        QueuePush(&obj->q2, QueuePop(&obj->q1));
    }
    int result = QueuePop(&obj->q1);
    QueuePush(&obj->q2, result);
    while (QueueSize(&obj->q2) > 0) {
        QueuePush(&obj->q1, QueuePop(&obj->q2));
    }
    return result;
}

int myStackEmpty(MyStack* obj) {
    return QueueSize(&obj->q1) == 0;
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
}

int main() {
    return 0;
}
