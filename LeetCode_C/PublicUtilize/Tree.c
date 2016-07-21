//
//  Tree.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/15.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "Tree.h"
#include <stdlib.h>

struct TreeNode * createTreeNode(int value) {
    if (value < 0 ) {
        return NULL;
    }
    struct TreeNode *result = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    result->val = value;
    result->left = NULL;
    result->right = NULL;
    return result;
}


//1. not clean the cache
//2. can't deal with elements with 0 
struct TreeNode *creatTree(int *input, int size) {
    if (input == NULL || size == 0) {
        return NULL;
    }
    struct TreeNode *cache[size];
    for (int i = 0; i < size; i++) {
        cache[i] = NULL;
    }
    struct TreeNode *root = createTreeNode(input[0]);
    cache[0] = root;
    struct TreeNode *parent = root;
    int cacheIndex = 0;
    for (int i = 1; i < size; i += 2) {
        if (input[i]) {
            struct TreeNode *left = createTreeNode(input[i]);
            parent->left = left;
            cache[i] = left;
        }
        if ((i + 1 < size)&& input[i+1]) {
            struct TreeNode *right = createTreeNode(input[i+1]);
            parent->right = right;
            cache[i+1] = right;
        }
        cacheIndex++;
        while (! cache[cacheIndex]) {
            cacheIndex++;
        }
        if (cacheIndex > size) {
            break;
        }
        parent = cache[cacheIndex];
    }
//    for (int i = 0; i < size; i++) {
//        if (cache[i]) {
//            printf("cache %d keep %d\n",i , (*cache[i]).val);
//        } else {
//            printf("cache %d empty\n", i);
//        }
//    }
    return root;
}



struct ValueNode {
    bool isNull;
    int value;
    struct ValueNode *next;
};

struct ValueNode *convertStringToValues(char *input) {
    struct ValueNode *head;
    
    return head;
}

int sizeOfNodes(struct ValueNode *head) {
    if (head == NULL) {
        return 0;
    }
    int result = 0;
    struct ValueNode *temp = head;
    while (temp) {
        result ++;
        temp = temp->next;
    }
    return result;
}

struct TreeNode *creatTreeByString(char *input) {
    if (input == NULL) {
        return NULL;
    }
    
    struct ValueNode *valueNodes = convertStringToValues(input);
    int size = sizeOfNodes(valueNodes);
    struct TreeNode *cache[size];
    for (int i = 0; i < size; i++) {
        cache[i] = NULL;
    }
    struct TreeNode *root = createTreeNode(valueNodes->value);
    struct TreeNode *parent = root;
    cache[0] = root;
    int cacheIndex = 0;
//    for (int i = 1; i < size; i += 2) {
//        if (input[i]) {
//            struct TreeNode *left = createTreeNode(input[i]);
//            parent->left = left;
//            cache[i] = left;
//        }
//        if ((i + 1 < size)&& input[i+1]) {
//            struct TreeNode *right = createTreeNode(input[i+1]);
//            parent->right = right;
//            cache[i+1] = right;
//        }
//        cacheIndex++;
//        while (! cache[cacheIndex]) {
//            cacheIndex++;
//        }
//        if (cacheIndex > size) {
//            break;
//        }
//        parent = cache[cacheIndex];
//    }
    //    for (int i = 0; i < size; i++) {
    //        if (cache[i]) {
    //            printf("cache %d keep %d\n",i , (*cache[i]).val);
    //        } else {
    //            printf("cache %d empty\n", i);
    //        }
    //    }
    return NULL;
}


void printOfTree(struct TreeNode *tree) {
    if (tree == NULL) {
        return;
    }
    printOfTree(tree->left);
    printOfTree(tree->right);
    printf(" %d", tree->val);

}