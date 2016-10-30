//
//  Tree.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/15.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "Tree.h"
#include <stdlib.h>
#include <string.h>



#pragma mark - Value Node

struct ValueNode {
    bool isNull;
    int value;
    struct ValueNode *next;
};


void printValueNode(struct ValueNode *root) {
    if (root == NULL) {
        printf("Empty value nodes");
        return;
    }
    struct ValueNode *p = root;
    int index = 0;
    while (p) {
        if (p->isNull) {
            printf("%d. _ Null\n", index);
        } else {
            printf("%d. _ %d\n", index ,p->value);
        }
        index ++;
        p = p->next;
    }
}

struct ValueNode *convertStringToValues(char *input) {
    struct ValueNode *head = NULL, *temp = NULL;
    char *p = input;
    int value = 0;
    bool isNull = false;
    bool isNegative = false;
    while (*p != '\0') {
        if (*p == '[') {
            
        }
        if (*p == '-') {
            isNegative = true;
        }
        if (*p >= '0' && *p <= '9') {
            value = value * 10 + *p - '0';
        }
        if (*p == 'n') {
            isNull = true;
        }
        if (*p == ',' || *p == ']') {
            struct ValueNode *newNode = (struct ValueNode *)malloc(sizeof(struct ValueNode));
            newNode->isNull = isNull;
            if (isNegative) {
                value = -value;
            }
            newNode->value = value;
            newNode->next = NULL;
            if (head == NULL) {
                head = newNode;
                temp = newNode;
            } else {
                temp->next = newNode;
                temp = newNode;
            }
            value = 0;
            isNegative = false;
            isNull = false;
        }
        p++;
    }
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

#pragma mark - Create Tree


struct TreeNode * createTreeNode(int value) {
    struct TreeNode *result = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    result->val = value;
    result->left = NULL;
    result->right = NULL;
    return result;
}


struct TreeNode *createTreeByString(char *input) {
    
//    input = "[]";
//    char *input = "[3,9,20,null,null,15,7]";
//    char *input = "[-2,0,-1,null,3,0,null,6,null,5,-5]";
    
    if (input == NULL) {
        return NULL;
    }
    if (strcmp( input , "[]")==1){
        return NULL;
    }
    struct ValueNode *valueNodes = convertStringToValues(input);
    struct ValueNode *pv = valueNodes->next;
    int size = sizeOfNodes(valueNodes);
    printValueNode(valueNodes);
    
    struct TreeNode *cache[size];
    for (int i = 0; i < size; i++) {
        cache[i] = NULL;
    }
    struct TreeNode *root = createTreeNode(valueNodes->value);
    struct TreeNode *parent = root;
    cache[0] = root;
    int pullIndex = 0;
    int pushIndex = 0;
    while (pv) {
        pushIndex ++;
        if (pv->isNull == false) {
            struct TreeNode *left = createTreeNode(pv->value);
            parent->left = left;
            cache[pushIndex] = left;
        }
        pushIndex ++;
        if (pv->next && pv->next->isNull == false) {
            struct TreeNode *right = createTreeNode(pv->next->value);
            parent->right = right;
            cache[pushIndex] = right;
        }
        
        pullIndex++;
        while (! cache[pullIndex]) {
            pullIndex++;
        }
        if (pullIndex > size) {
            break;
        }
        parent = cache[pullIndex];
        if (pv->next->next) {
            pv = pv->next->next;
        } else {
            pv = NULL;
        }
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



#pragma mark -

void printTree(struct TreeNode *tree) {
    if (tree == NULL) {
        return;
    }
    printTree(tree->left);
    printTree(tree->right);
    printf(" %d", tree->val);
    
}
