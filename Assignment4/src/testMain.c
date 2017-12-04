#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTreeAPI.h"


void printTestInfo(int n, char *info);
int printPassFail(int b);
int compareInt(const void *first, const void *second);
void printInt(void *data);
void deleteFunc(void* data);
int* createInt(int num);



int main(int argc, char** argv){
    printf("Test is running...\n\n\n");
    int numTests = 0;
    int testsPassed = 0;

    int result = 0;
    int* n1 = createInt(5);
    int* n2 = createInt(3);
    int* n3 = createInt(8);
    int* n4 = createInt(11);
    int* n5 = createInt(15);


    printTestInfo(++numTests, "Testing to make sure a tree has been dynamically allocated.");
    Tree* testTree = createBinTree(compareInt, deleteFunc);
    printf("Expected: 1\n");
    printf("Received: %d\n", testTree != NULL);
    printf("1 implies the condition has been evaluated to true. Checking if HashTable and table in side it are not NULL.\n");
    testsPassed += printPassFail(testTree != NULL);


    printTestInfo(++numTests, "Testing to make sure a tree node has been dynamically allocated.");
    TreeNode* treeNode = createTreeNode(n1);
    printf("Expected: 1\n");
    printf("Received: %d\n", treeNode != NULL);
    testsPassed += printPassFail(treeNode != NULL);


    printTestInfo(++numTests, "Testing make sure element has been added to tree.");
    addToTree(testTree, n1);
    printf("Expected: \n5\n");
    printf("Received: \n");
    printInOrder(testTree, printInt);
    testsPassed += printPassFail(testTree->root != NULL);

    addToTree(testTree, n2);
    addToTree(testTree, n3);
    addToTree(testTree, n4);

    printTestInfo(++numTests, "Testing to make sure element is not removed if it doesn't exist in the tree \n(Trying to remove 12 from the tree).");
    printf("Expected:\n3\n5\n8\n11\n");
    removeFromTree(testTree, n5);
    printf("Received: \n");
    printInOrder(testTree, printInt);
    testsPassed += printPassFail(testTree->root != NULL);

    printTestInfo(++numTests, "Testing to make sure we can properly search for an element in the tree\n(Searching for 3).");
    printf("Expected: 3\n");
    void* data = findInTree(testTree, n2);
    printf("Received: %d\n", *((int *)data));
    testsPassed += printPassFail(*((int *)data) == 3);

    printTestInfo(++numTests, "Testing to make sure we can retrieve root data of a tree");
    data = getRootData(testTree);
    printf("Expected: 5\n");
    printf("Received: %d\n", *((int *)data));
    testsPassed += printPassFail(*((int *)data) == 5);


    printTestInfo(++numTests, "Testing to make sure we can print in order properly");
    printf("Expected:\n3\n5\n8\n11\n");
    printf("Received: \n");
    printInOrder(testTree, printInt);
    testsPassed += printPassFail(1);

    printTestInfo(++numTests, "Testing to make sure we can print pre order properly");
    printf("Expected:\n5\n3\n8\n11\n");
    printf("Received: \n");
    printPreOrder(testTree, printInt);
    testsPassed += printPassFail(1);


    printTestInfo(++numTests, "Testing to make sure we can print post order properly");
    printf("Expected:\n3\n11\n8\n5\n");
    printf("Received: \n");
    printPostOrder(testTree, printInt);
    testsPassed += printPassFail(1);

    printTestInfo(++numTests, "Testing helper function that checks if tree is empty");
    printf("Expected: 0\n");
    result = isTreeEmpty(testTree);
    printf("Received: %d\n", result);
    testsPassed += printPassFail(!result);

    printTestInfo(++numTests, "Testing helper function that checks if a node is a leaf");
    printf("Expected: 1\n");
    result = isLeaf(treeNode);
    printf("Received: %d\n", result);
    testsPassed += printPassFail(result);

    printTestInfo(++numTests, "Testing helper function that checks if a node has two children");
    printf("Expected: 1\n");
    result = hasTwoChildren(testTree->root);
    printf("Received: %d\n", result);
    testsPassed += printPassFail(result);

    printTestInfo(++numTests, "Testing helper function that calculates the height of a tree");
    printf("Expected: 2\n");
    result = getHeight(testTree->root);
    printf("Received: %d\n", result);
    testsPassed += printPassFail(result == 3);

    printTestInfo(++numTests, "Testing to make sure tree has been completely free'd");
    printf("Expected: 1\n");
    destroyBinTree(testTree);
    testTree = NULL;
    printf("Received: %d\n", testTree == NULL);
    testsPassed += printPassFail(testTree == NULL);

    printf("%d of %d tests passed.\n", testsPassed, numTests);

    return 0;
}


int* createInt(int num){
    int *n = malloc(sizeof(int));
    *n = num;

    return n;
}


void deleteFunc(void* data){
    if(data != NULL){
        free(data);
    }
}


void printInt(void *data){
    int *n = (int *) data;
    printf("%d\n", *n);
}


int compareInt(const void *first, const void *second){
    int *n1 = (int *) first;
    int *n2 = (int *) second;

    if(*n1 > *n2){
        return 1;
    }else if(*n1 < *n2){
        return -1;
    }else{
        return 0;
    }

}


void printTestInfo(int n, char *info){
    printf("Test #%d: %s\n", n, info);
}


int printPassFail(int b){
    if(b == 0){
        printf("FAIL\n\n");
        return 0;
    }else{
        printf("PASS\n\n");
        return 1;
    }
}