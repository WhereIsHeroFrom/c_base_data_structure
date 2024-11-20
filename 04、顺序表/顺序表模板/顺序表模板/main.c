#include <stdio.h>
#include <stdlib.h>

// 定义顺序表的结构
typedef struct {
    int* elements;
    size_t size;
    size_t capacity;
} SequentialList;

// 顺序表的初始化
void SequentialListInit(SequentialList* list, int capacity) {
    list->elements = (int*)malloc(sizeof(int) * capacity);
    list->size = 0;
    list->capacity = capacity;
}

// 顺序表的销毁
void SequentialListDestroy(SequentialList* list) {
    if (list->elements != NULL) {
        free(list->elements);
        list->elements = NULL;
    }
}

// 顺序表的元素个数
size_t SequentialListSize(const SequentialList* list) {
    return list->size;
}

// 顺序表的元素插入
void SequentialListInsert(SequentialList* list, int index, int element) {
    if (index < 0 || index > list->size) {
        printf("Invalid index\n");
        return;
    }

    if (list->size == list->capacity) {
        int* newElements = (int*)realloc(list->elements, sizeof(int) * list->capacity * 2);
        if (newElements == NULL) {
            printf("Failed to allocate memory\n");
            return;
        }
        list->elements = newElements;
        list->capacity *= 2;
    }

    for (size_t i = list->size; i > index; i--) {
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[index] = element;
    list->size++;
}

// 顺序表的元素删除
void SequentialListDelete(SequentialList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }

    for (size_t i = index; i < list->size; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
}

// 顺序表的元素查找
int SequentialListFind(const SequentialList* list, int element) {
    for (size_t i = 0; i < list->size; i++) {
        if (list->elements[i] == element) {
            return i;
        }
    }
    return -1;
}

// 顺序表的元素索引
int SequentialListIndex(const SequentialList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return -1;
    }
    return list->elements[index];
}

// 顺序表的元素修改
void SequentialListSet(SequentialList* list, int index, int element) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return;
    }
    list->elements[index] = element;
}

// 顺序表的完整源码
int main() {
    SequentialList list;
    SequentialListInit(&list, 1);

    for (int i = 0; i < 10; i++) {
        SequentialListInsert(&list, i, i * 10);
    }

    printf("Size: %llu\n", SequentialListSize(&list));

    int elem = SequentialListIndex(&list, 2);
    printf("Element found(%d) in index(%d)\n", elem, 2);

    int index = SequentialListFind(&list, 15);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    }
    else {
        printf("Element not found\n");
    }

    SequentialListSet(&list, 3, 60);

    printf("Updated list:\n");
    for (size_t i = 0; i < list.size; i++) {
        printf("%d ", list.elements[i]);
    }

    SequentialListDestroy(&list);

    return 0;
}