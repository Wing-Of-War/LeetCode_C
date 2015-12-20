//
//  lowest-common-ancestor-of-a-binary-search-tree.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/20.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "lowest-common-ancestor-of-a-binary-search-tree.h"
#include "Tree.h"
#include "stdlib.h"

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (p->val > q->val) {
        struct TreeNode *temp = p;
        p = q;
        q = temp;
    }
    
    if ((root->val < q->val) && (root->val > p->val)) {
        return root;
    }
    
    if (root->val == p->val || root->val == q->val) {
        return root;
    }
    if (root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else {
        return lowestCommonAncestor(root->right, p, q);
    }
}

void testLowestCommonAncestor(void) {
    struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node2->left = node1;
    node2->right = node3;
    

    struct TreeNode *node4 = lowestCommonAncestor(node2, node3, node1);
    printf("reulst %d", node4->val);
}
