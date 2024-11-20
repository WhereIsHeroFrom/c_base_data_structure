#include <stdio.h>
#include <stdlib.h>

#define eleType int

typedef struct {
    eleType* elements;
    size_t size;
    size_t capacity;
} Stack;

void StackCreate(Stack* stk) {
    stk->elements = (eleType*)malloc(sizeof(eleType) * 8);
    stk->size = 0;
    stk->capacity = 8;
}

void StackDestroy(Stack* stk) {
    free(stk->elements);
    stk->elements = NULL;
    stk->size = 0;
    stk->capacity = 0;
}

void StackResize(Stack* stk) {
    eleType* new_elements = (eleType*)realloc(stk->elements, sizeof(eleType) * stk->capacity * 2);
    stk->elements = new_elements;
    stk->capacity *= 2;
}

void StackPush(Stack* stk, eleType element) {
    if (stk->size == stk->capacity) {
        StackResize(stk);
    }
    stk->elements[stk->size++] = element;
}

eleType StackPop(Stack* stk) {
    if (stk->size == 0) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stk->elements[--stk->size];
}

eleType StackTop(Stack* stk) {
    if (stk->size == 0) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return stk->elements[stk->size - 1];
}

int StackGetSize(Stack* stk) {
    return stk->size;
}



typedef struct {
    Stack s1;
    Stack s2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    StackCreate(&obj->s1);
    StackCreate(&obj->s2);
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->s1, x);
}

int myQueuePop(MyQueue* obj) {
    if (StackGetSize(&obj->s2) == 0) {
        while (StackGetSize(&obj->s1)) {
            StackPush(&obj->s2, StackPop(&obj->s1));
        }
    }
    return StackPop(&obj->s2);
}

int myQueuePeek(MyQueue* obj) {
    if (StackGetSize(&obj->s2) == 0) {
        while (StackGetSize(&obj->s1)) {
            StackPush(&obj->s2, StackPop(&obj->s1));
        }
    }
    return StackTop(&obj->s2);
}

int myQueueEmpty(MyQueue* obj) {
    return StackGetSize(&obj->s1) + StackGetSize(&obj->s2) == 0;
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->s1);
    StackDestroy(&obj->s2);
}

int main() {
    return 0;
}