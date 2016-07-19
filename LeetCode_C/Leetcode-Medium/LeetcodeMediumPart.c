//
//  LeetcodeMediumPart.c
//  LeetCode_C
//
//  Created by JUE DUKE on 7/17/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "LeetcodeMediumPart.h"
#include "Tree.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode * findLowestRight(struct TreeNode *root) {
    if (root->right == NULL) {
        return root;
    }
    struct TreeNode *rightNode = root->right;
    while (rightNode->right) {
        rightNode = rightNode->right;
    }
    return rightNode;
}

void flatten(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->left) {
        struct TreeNode *leftNode = findLowestRight(root->left);
        leftNode->right = root->right;
        root->right = root->left;
        flatten(root->right);
    }
    if (root->right == NULL) {
        return;
    }
}


void runMediumPart() {
    
}