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

int main() {
    Stack stk;

    StackCreate(&stk);
    StackPush(&stk, 10);
    StackPush(&stk, 20);
    StackPush(&stk, 30);
    printf("栈顶元素: %d\n", StackTop(&stk));
    printf("出栈: %d\n", StackPop(&stk));
    printf("栈的大小: %d\n", StackGetSize(&stk));
    StackDestroy(&stk);

    return 0;
}