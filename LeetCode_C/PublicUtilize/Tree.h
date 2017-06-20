//
//  Tree.h
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/15.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
//    struct TreeNode *parent;
};

struct TreeNode *createTreeByString(char *input) ;

struct TreeNode *createTree(int *input, int size) ;

struct TreeNode * createTreeNode(int value) ;

void printTree(struct TreeNode *tree);

#endif /* Tree_h */
