#include <stdio.h>
#include <stdlib.h>

#define eleType int

typedef struct Node {
    eleType data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    size_t size;
} Stack;

void StackCreate(Stack* stk) {
    stk->head = NULL;
    stk->size = 0;
}

void StackDestroy(Stack* stk) {
    while (stk->head) {
        Node* next = stk->head->next;
        free(stk->head);
        stk->head = next;
    }
    stk->size = 0;
}

void StackPush(Stack* stk, eleType element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = stk->head;
    stk->head = newNode;
    stk->size++;
}

eleType StackPop(Stack* stk) {
    if (stk->size == 0) {
        printf("Stack underflow!\n");
        exit(1);
    }
    eleType result = stk->head->data;
    Node* next = stk->head->next;
    free(stk->head);
    stk->head = next;
    stk->size--;
    return result;
}

eleType StackTop(Stack* stk) {
    if (stk->size == 0) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return stk->head->data;
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