//
//  lowest-common-ancestor-of-a-binary-search-tree.h
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/20.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#ifndef lowest_common_ancestor_of_a_binary_search_tree_h
#define lowest_common_ancestor_of_a_binary_search_tree_h


//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

//Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
//
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
//
//_______6______
///              \
//___2__          ___8__
///      \        /      \
//0      _4       7       9
///  \
//3   5
//For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

#include <stdio.h>

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q);

void testLowestCommonAncestor(void);

#endif /* lowest_common_ancestor_of_a_binary_search_tree_h */
