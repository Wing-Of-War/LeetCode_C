//
//  LeetcodeMediumPart.c
//  LeetCode_C
//
//  Created by JUE DUKE on 7/17/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "LeetcodeMediumPart.h"
#include "Tree.h"
#include <stdlib.h>

#pragma mark - 442. Find All Duplicates in an Array
//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
//https://leetcode.com/problems/find-all-duplicates-in-an-array/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmpfunc(const void *a, const void *b) {
    if (*(int *)b > *(int *)a) {
        return -1;
    } else if (*(int *)b < *(int *)a ) {
        return 1;
    }
    return 0;  //I can't figure out.
}

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int32_t), cmpfunc);
    int *result = (int *)malloc(sizeof(int) * numsSize);
    int size = 0;
    for (int i =0; i < numsSize-1; i++) {
        if (nums[i] == nums[i+1]) {
            result[size] = nums[i];
            size++;
        }
    }
    *returnSize = size;
    return result;
}

void run442() {
    
}


#pragma mark - 113. Path Sum II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
//    return NULL;
//}



#pragma mark -
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
    run442();
}
