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
struct TreeNode *creatTree(int *input, int size) {
    if (input == NULL || size == 0) {
        return NULL;
    }
    struct TreeNode *cache[size];
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
        if ( (i + 1 < size)&& input[i+1]) {
            struct TreeNode *right = createTreeNode(input[i+1]);
            parent->right = right;
            cache[i+1] = right;
        }
        cacheIndex++;
        while (! cache[cacheIndex]) {
            cacheIndex++;
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

void printOfTree(struct TreeNode *tree) {
    if (tree == NULL) {
//        printf(" #");
        return;
    }
    printOfTree(tree->left);
    printOfTree(tree->right);
    printf(" %d", tree->val);

}