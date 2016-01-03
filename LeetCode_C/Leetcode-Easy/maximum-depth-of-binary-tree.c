//
//  maximum-depth-of-binary-tree.c
//  LeetCode_C
//
//  Created by JUE DUKE on 1/4/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "maximum-depth-of-binary-tree.h"
#include "Tree.h"


int maxDepth(struct TreeNode* root) {
    
    if(root == NULL) {
        return 0;
    }
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return left > right ? left+1 :right+1;
}