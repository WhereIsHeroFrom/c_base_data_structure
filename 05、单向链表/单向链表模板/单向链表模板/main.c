#include <stdio.h>
#include <stdlib.h>

#define eleType int

// 单向链表结点的定义
typedef struct ListNode {
    eleType data;
    struct ListNode* next;
}ListNode;

// 单向链表的定义
typedef struct LinkedList {
    struct ListNode* head;
    size_t size;
}LinkedList;

// 创建链表
void LinkedListCreate(LinkedList* list) {
    // 初始化链表头为 NULL
    list->head = NULL;
    list->size = 0;
}

// 销毁链表
void LinkedListDestroy(LinkedList* list) {
    // 遍历链表，释放每个结点
    while (list->head) {
        ListNode* temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    list->size = 0;
}

// 往链表 list 的第 i 个位置插入一个值为 value 的结点
void LinkedListInsert(LinkedList* list, int i, eleType value) {
    if (i < 0 || i > list->size) {
        printf("Invalid index\n");
        return;
    }

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = value;

    if (i == 0) {
        newNode->next = list->head;
        list->head = newNode;
    }
    else {
        ListNode* current = list->head;
        for (int j = 0; j < i - 1; j++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

// 删除链表 list 的第 i 个结点
void LinkedListRemove(LinkedList* list, int i) {
    if (i < 0 || i >= list->size) {
        printf("Invalid index\n");
        return;
    }

    if (i == 0) {
        ListNode* next = list->head->next;
        free(list->head);
        list->head = next;
    }
    else {
        ListNode* current = list->head;
        for (int j = 0; j < i - 1; j++) {
            current = current->next;
        }
        ListNode* next = current->next->next;
        free(current->next);
        current->next = next;
    }
    list->size--;
}

// 查找链表 list 中值为 value 的结点，并返回
ListNode* LinkedListFind(LinkedList* list, eleType value) {
    ListNode* current = list->head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 获取链表 list 中第 i 个结点
ListNode* LinkedListGet(LinkedList* list, int i) {
    if (i < 0 || i >= list->size) {
        printf("Invalid index\n");
        return NULL;
    }

    ListNode* current = list->head;
    for (int j = 0; j < i; j++) {
        current = current->next;
    }
    return current;
}

// 更新链表 list 中第 i 个结点的值为 value
void LinkedListUpdate(LinkedList* list, int i, eleType value) {
    ListNode* node = LinkedListGet(list, i);
    if (node != NULL) {
        node->data = value;
    }
    else {
        printf("Invalid index\n");
    }
}

// 打印链表
void LinkedListPrint(LinkedList* list) {
    ListNode* current = list->head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // 创建一个链表
    LinkedList list;
    list.head = NULL;
    list.size = 0;

    // 插入元素
    LinkedListInsert(&list, 0, 10);
    LinkedListInsert(&list, 1, 20);
    LinkedListInsert(&list, 2, 30);
    LinkedListInsert(&list, 3, 40);

    // 打印原始链表
    printf("Original List: ");
    LinkedListPrint(&list);

    // 删除第 2 个结点
    LinkedListRemove(&list, 2);

    // 更新第 1 个结点的值
    LinkedListUpdate(&list, 1, 100);

    // 查找值为 30 的结点
    ListNode* found = LinkedListFind(&list, 30);
    if (found != NULL) {
        printf("Element found!\n");
    }
    else {
        printf("Element not found!\n");
    }

    // 获取第 2 个结点
    ListNode* node = LinkedListGet(&list, 2);
    if (node != NULL) {
        printf("Element at index 2: %d\n", node->data);
    }
    else {
        printf("Element at index 2 not found!\n");
    }

    // 打印更新后的链表
    printf("Updated List: ");
    LinkedListPrint(&list);

    return 0;
}