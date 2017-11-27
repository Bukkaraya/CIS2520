#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTreeAPI.h"


TreeNode* createTreeNode(TreeDataPtr data){
    TreeNode* tn = malloc(sizeof(TreeNode));
    tn->right = NULL;
    tn->left = NULL;
    tn->data = data;

    return tn;
}


Tree* createBinTree(CompareFunc compare, DeleteFunc del){
    Tree* tree = malloc(sizeof(Tree));
    tree->root = NULL;
    tree->compareFunc = compare;
    tree->deleteFunc = del;

    return tree;
}


void destroyBinTree(Tree *toDestroy){
    destroyTree(toDestroy->root, toDestroy->deleteFunc);
    free(toDestroy);
}


void addToTree(Tree *theTree, TreeDataPtr data){
    theTree->root = insert(theTree->root, data, theTree->compareFunc);
}


void removeFromTree(Tree* theTree, TreeDataPtr data){
    theTree->root = deleteNode(theTree->root, data, theTree->deleteFunc, theTree->compareFunc);
}


TreeDataPtr findInTree(Tree* theTree, TreeDataPtr data){
    return find(theTree->root, data, theTree->compareFunc);
}


TreeDataPtr getRootData(Tree * theTree){
    if(theTree){
        if(theTree->root != NULL){
            return theTree->root->data;
        }
    }

    return NULL;
}


void printInOrder(Tree* theTree, PrintFunc printData){
    inOrder(theTree->root, printData);
}


void printPreOrder(Tree* theTree, PrintFunc printData){
    preOrder(theTree->root, printData);
}


void printPostOrder(Tree* theTree, PrintFunc printData){
    postOrder(theTree->root, printData);
}


int isTreeEmpty(Tree* theTree){
    if(theTree){
        if(theTree->root != NULL){
            return 0;
        }
    }

    return 1;
}


int isLeaf( TreeNode * treeNode){
    if(treeNode->right == NULL && treeNode->left == NULL){
        return 1;
    }

    return 0;
}


TreeNode* findMinimum(TreeNode* root){
    if(root == NULL){
        return NULL;
    }else if(root->left == NULL){
        return root;
    }

    findMinimum(root->left);
}


int hasTwoChildren(TreeNode* treeNode){
    if(treeNode != NULL){
        if(treeNode->left != NULL && treeNode->right != NULL){
            return 1;
        }
    }

    return 0;
}


int getHeight(TreeNode* treeNode){
    if(treeNode == NULL){
        return 0;
    }

    int leftHeight = getHeight(treeNode->left) + 1;
    int rightHeight = getHeight(treeNode->right) + 1;

    if(leftHeight > rightHeight){
        return leftHeight;
    }else{
        return rightHeight;
    }
}


TreeNode* insert(TreeNode* root, TreeDataPtr data, CompareFunc compare){
    if(root == NULL){
        TreeNode* temp = createTreeNode(data);
        return temp;
    }

    if(compare(data, root->data) == 1){
        root->right = insert(root->right, data, compare);
    }else if(compare(data, root->data) == -1){
        root->left = insert(root->left, data, compare);
    }

    return root;

}


TreeNode* deleteNode(TreeNode* root, TreeDataPtr data, DeleteFunc del, CompareFunc compare){
    TreeNode* temp;
    void* removedData;
    
    if(root == NULL){
        return NULL;
    }else if(compare(data, root->data) == 1){
        root->right = deleteNode(root->right, data, del, compare);
    }else if(compare(data, root->data) == -1){
        root->left = deleteNode(root->left, data, del, compare);
    }else{
        if(hasTwoChildren(root)){
            temp = findMinimum(root->right);
            removedData = root->data;
            del(removedData);

            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data, del, compare);
        }else{
            temp = root;
            if(root->left == NULL){
                root = root->right;
            }else if(root->right == NULL){
                root = root->left;
            }
        }
    }

    free(temp);
    return root;
}


void destroyTree(TreeNode* root, DeleteFunc deleteFunc){
    if(root == NULL){
        return;
    }

    destroyTree(root->left, deleteFunc);
    destroyTree(root->right, deleteFunc);
    deleteFunc(root->data);
    free(root);
}


void inOrder(TreeNode* root, PrintFunc printData){
    if(root == NULL){
        return;
    }

    inOrder(root->left, printData);
    printData(root->data);
    inOrder(root->right, printData);
}


void preOrder(TreeNode* root, PrintFunc printData){
    if(root == NULL){
        return;
    }

    printData(root->data);
    preOrder(root->left, printData);
    preOrder(root->right, printData);
}


void postOrder(TreeNode* root, PrintFunc printData){
    if(root == NULL){
        return;
    }

    postOrder(root->left, printData);
    postOrder(root->right, printData);
    printData(root->data);
}


TreeDataPtr find(TreeNode* root, TreeDataPtr data, CompareFunc compare){
    if(root == NULL){
        return NULL;
    }

    if(compare(data, root->data) == 1){
        return find(root->right, data, compare);
    }else if(compare(data, root->data) == -1){
        return find(root->left, data, compare);
    }else{
        return root->data;
    }

}