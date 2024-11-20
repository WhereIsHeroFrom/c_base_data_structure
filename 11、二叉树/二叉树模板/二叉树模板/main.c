#include <stdio.h>
#include <stdlib.h>

#define eleType char

typedef struct TreeNode {
    eleType val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef struct Tree {
    TreeNode* nodes;
    TreeNode* root;
    size_t nodeSize;
}Tree;

void TreeInit(Tree* t, int size) {
    t->nodeSize = size;
    t->nodes = (TreeNode*)malloc(sizeof(TreeNode) * size);
    t->root = NULL;
}

void TreeDestroy(Tree* t) {
    free(t->nodes);
    t->nodes = NULL;
    t->nodeSize = 0;
    t->root = NULL;
}

TreeNode* TreeGetNode(Tree* t, int id) {
    return &t->nodes[id];
}

void visit(TreeNode* node) {
    printf("%c", node->val);
}

TreeNode* createRecursively(Tree* t, eleType a[], int size, int nodeId, eleType nullNode) {
    if (nodeId >= size || a[nodeId] == nullNode) {
        return NULL;
    }
    TreeNode* nowNode = TreeGetNode(t, nodeId);
    nowNode->val = a[nodeId];
    nowNode->left = createRecursively(t, a, size, nodeId * 2, nullNode);
    nowNode->right = createRecursively(t, a, size, nodeId * 2 + 1, nullNode);
    return nowNode;
}

void TreeCreate(Tree* t, eleType a[], int size, char nullNode) {
    t->root = createRecursively(t, a, size, 1, nullNode);
}

void preOrder(Tree* t, TreeNode* node) {
    if (node) {
        visit(node);
        preOrder(t, node->left);
        preOrder(t, node->right);
    }
}

void TreePreOrderTraversal(Tree* t) {
    preOrder(t, t->root);
}

void inOrder(Tree* t, TreeNode* node) {
    if (node) {
        inOrder(t, node->left);
        visit(node);
        inOrder(t, node->right);
    }
}

void TreeInOrderTraversal(Tree* t) {
    inOrder(t, t->root);
}

void postOrder(Tree* t, TreeNode* node) {
    if (node) {
        postOrder(t, node->left);
        postOrder(t, node->right);
        visit(node);
    }
}

void TreePostOrderTraversal(Tree* t) {
    postOrder(t, t->root);
}

int main()
{
    const char nullNpde = '-';
    char a[15] = {
        nullNpde, 'a', 'b', 'c', 'd',
        nullNpde, 'e', 'f', 'g', 'h',
        nullNpde, nullNpde, nullNpde, nullNpde, 'i'
    };

    Tree T;
    TreeInit(&T, 15);

    TreeCreate(&T, a, 15, nullNpde);
    TreePreOrderTraversal(&T); printf("\n");
    TreeInOrderTraversal(&T); printf("\n");
    TreePostOrderTraversal(&T); printf("\n");

    TreeDestroy(&T);
    return 0;
}
