//
//  balanced-binary-tree.c
//  LeetCode_C
//
//  Created by JUE DUKE on 16/1/3.
//  Copyright © 2016年 JUE DUKE. All rights reserved.
//

#include "balanced-binary-tree.h"
#include "Tree.h"
#include <stdlib.h>

int deep(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int L = deep(root->left);
    int R = deep(root->right);
    int deep = L > R ? L : R;
    return 1 + deep;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    int l = deep(root->left);
    int r = deep(root->right);
    if (abs(l - r) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
    
}


