//
//  same-tree.c
//  LeetCode_C
//
//  Created by JUE DUKE on 1/4/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "same-tree.h"
#include "Tree.h"


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
    if (p==NULL && q==NULL) {
        return true;
    }
    if ((p==NULL && q!=NULL) || (p !=NULL && q==NULL)) {
        return false;
    }
    
    if (p-> val == q->val) {
        return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    } else {
        return false;
    }
}