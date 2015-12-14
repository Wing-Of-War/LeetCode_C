//
//  invert-binary-tree.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/15.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "invert-binary-tree.h"
#include "Tree.h"

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==NULL) {
        return NULL;
    }
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    if(root->right) {
        invertTree(root->right);
    }
    if(root->left) {
        invertTree(root->left);
    }
    return root;
}