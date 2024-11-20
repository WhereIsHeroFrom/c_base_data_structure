#include <stdio.h>

#define maxHashSize 100000
#define eleType int
#define empty -191028223

int hashArray[maxHashSize];

int hashFunc(eleType val) {
    int x = val % maxHashSize;
    if (x < 0) x += maxHashSize;
    return x;
}

void hashInit() {
    for (int i = 0; i < maxHashSize; ++i) {
        hashArray[i] = empty;
    }
}

int hashInsert(eleType val) {
    int key = hashFunc(val);
    while (1) {
        if (hashArray[key] == empty) {
            hashArray[key] = val;
            return key;
        }
        else if (hashArray[key] == val) {
            return key;
        }
        key = key + 1;
        if (key >= maxHashSize) {
            key = 0;
        }
    }
}

int hashDelete(eleType val) {
    int key = hashFunc(val);
    while (1) {
        if (hashArray[key] == empty) {
            return 0;
        }
        else if (hashArray[key] == val) {
            hashArray[key] = empty;
            return 1;
        }
        key = key + 1;
        if (key >= maxHashSize) {
            key = 0;
        }
    }
}

int hashFind(eleType val, int* isFind) {
    int key = hashFunc(val);
    while (1) {
        if (hashArray[key] == empty) {
            *isFind = 0;
            return key;
        }
        else if (hashArray[key] == val) {
            *isFind = 1;
            return key;
        }
        key = key + 1;
        if (key >= maxHashSize) {
            key = 0;
        }
    }
}

int main() {
    hashInit();
    int x1 = hashInsert(123);
    int x2 = hashInsert(35435);
    int x3 = hashInsert(315435);
    int x4 = hashInsert(353435);
    printf("%d %d %d %d\n", x1, x2, x3, x4);
    hashDelete(123);
    int isFind;
    hashFind(123, &isFind);
    printf("%d\n", isFind);
    return 0;
}
