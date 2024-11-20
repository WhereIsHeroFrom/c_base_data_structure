#include <stdio.h>
#include <stdlib.h>

#define eleType char

struct TreeNode;

typedef struct ListNode {
    struct TreeNode* data;
    struct ListNode* next;
}ListNode;

typedef struct TreeNode {
    eleType data;
    ListNode* childrenHead;
}TreeNode;

void AddTreeChild(TreeNode* parent, TreeNode* child) {
    ListNode* childNode = (ListNode*)malloc(sizeof(ListNode));
    childNode->next = NULL;
    childNode->data = child;

    if (parent->childrenHead == NULL) {
        parent->childrenHead = childNode;
    }
    else {
        childNode->next = parent->childrenHead;
        parent->childrenHead = childNode;
    }
}

typedef struct Tree {
    TreeNode* nodes;
    TreeNode* root;
}Tree;

void TreeCreate(Tree* t, int size) {
    t->nodes = (TreeNode*)malloc(sizeof(TreeNode) * size);
    t->root = NULL;
    for (int i = 0; i < size; ++i) {
        t->nodes[i].childrenHead = NULL;
    }
}

void TreeDestroy(Tree* t) {
    free(t->nodes);
    t->nodes = NULL;
    t->root = NULL;
}

TreeNode* TreeGetNode(Tree* t, int id) {
    return &t->nodes[id];
}

void TreeSetRoot(Tree* t, int id) {
    t->root = TreeGetNode(t, id);
}

void TreeAddChild(Tree* t, int parentId, int childId) {
    TreeNode* parentNode = TreeGetNode(t, parentId);
    TreeNode* childNode = TreeGetNode(t, childId);
    AddTreeChild(parentNode, childNode);
}

void TreeAssignData(Tree* t, int id, eleType data) {
    TreeGetNode(t, id)->data = data;
}

void TreePrint(Tree* t, TreeNode* node) {
    if (node == NULL) {
        node = t->root;
    }
    printf("%c", node->data);
    ListNode* tmp = node->childrenHead;
    while (tmp) {
        TreePrint(t, tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    Tree T;
    TreeCreate(&T, 9);
    TreeSetRoot(&T, 0);
    TreeAssignData(&T, 0, 'a');
    TreeAssignData(&T, 1, 'b');
    TreeAssignData(&T, 2, 'c');
    TreeAssignData(&T, 3, 'd');
    TreeAssignData(&T, 4, 'e');
    TreeAssignData(&T, 5, 'f');
    TreeAssignData(&T, 6, 'g');
    TreeAssignData(&T, 7, 'h');
    TreeAssignData(&T, 8, 'i');

    TreeAddChild(&T, 0, 2);
    TreeAddChild(&T, 0, 1);
    TreeAddChild(&T, 1, 3);
    TreeAddChild(&T, 2, 5);
    TreeAddChild(&T, 2, 4);
    TreeAddChild(&T, 3, 8);
    TreeAddChild(&T, 3, 7);
    TreeAddChild(&T, 3, 6);

    TreePrint(&T, T.root);

    return 0;
}