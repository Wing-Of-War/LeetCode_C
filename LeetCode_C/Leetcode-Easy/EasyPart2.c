//
//  EasyPart2.c
//  LeetCode_C
//
//  Created by Jue on 2017/6/20.
//  Copyright © 2017年 JUE DUKE. All rights reserved.
//

#include "EasyPart2.h"
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


#pragma mark - 557. Reverse Words in a String III


/*
 convert input as int, size_t is unsigned long, 0-1 is the largest number..
 */

void reverseWord(char *s, int front, int back) {
    while (front <= back) {
        char t = s[front];
        s[front] = s[back];
        s[back] = t;
        front ++;
        back --;
    }
}

char* reverseWords(char* s) {
    /* Version 1 with inappropriate input.
    size_t length = strlen(s);
    size_t index_f = 0, index_b, index_s;
    char *result = malloc(sizeof(char) * length);
    for (int i = 0 ; i < length; i++) {
        result[i] = ' ';
    }
    result[length] = '\0';
    for (size_t index = 0; index < length; index++) {
        if (s[index] == ' ') {
            index_s = index;
            index_b = index_s -1;
            while (index_b > index_f) {
                result[index_f] = s[index_b];
                result[index_b] = s[index_f];
                index_f ++;
                index_b --;
            }
            if (index_b == index_f) {
                result[index_b] = s[index_b];
            }
            result[index] = s[index];
            index_f = index+1;
        }
        
    }
    if (length != 0) {
        index_b = length -1;
        while (index_b > index_f) {
            result[index_f] = s[index_b];
            result[index_b] = s[index_f];
            index_f ++;
            index_b --;
        }
        if (index_b == index_f) {
            result[index_b] = s[index_b];
        }
    } */
    size_t length = strlen(s);
    size_t index_f = 0;
    for (int index = 0; index <= length ; index++) {
        if (s[index] == ' ' || index == length) {
            reverseWord(s, (int)index_f, index-1);
            index_f = index+1;
        }
    }
    return s;
}

void run556() {
    
/* Not a suitable input test
//    char *input = "Let's take LeetCode contest";
//    char *output = reverseWords(input);
//    printf("%s\n", output);
//    char *input = "";
//    char *output = reverseWords(input);
//    printf("%s\n", output);
 */
    
//    char input[] = "Let's take LeetCode contest";
//    input[0] = '1';
//    reverseWords(input);
//    printf("%s \n", input);
    
    char input[] = "";
    reverseWords(input);
    printf("%s \n", input);
    
    
    
//    char input[] = "I love u";
//    reverseWords(input);
//    printf("%s \n", input);


}

#pragma mark - 476. Number Complement


int findComplement(int num) {
    int mask = 0;
    while (mask < num) {
        mask = (mask << 1) + 1;
    }
    return mask ^ num;
}

void run476() {
    unsigned result = findComplement(5);
    printf("\n%u \n", result);
    unsigned result2 = findComplement(1);
    printf("\n%u \n", result2);
}

#pragma mark - 561. Array Partition I


int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int sum = 0;
    for (int i = 0; i < numsSize/2; i++) {
        sum += nums[i*2];
    }
    return sum;
}

void run561() {
    int nums[] = {1,2,3,4};
    arrayPairSum(nums, 4);
}

#pragma mark - 617. Merge Two Binary Trees

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    /* 22ms
     
    if (t1 ==NULL) {
        return t2;
    }
    if (t2 == NULL) {
        return t1;
    }
    t1 ->val += t2->val;
    t1 ->left = mergeTrees(t1->left, t2->left);
    t1 ->right = mergeTrees(t1->right, t2->right);
    */
    
    /* 26ms
    if (t1 != NULL && t2 != NULL) {
        t1 ->val += t2->val;
    }else {
        return t1 != NULL ? t1 : t2;
    }
    
    t1 ->left = mergeTrees(t1->left, t2->left);
    t1 ->right = mergeTrees(t1->right, t2->right);
     */
    
    
    if (t1 != NULL && t2 != NULL) {
        t1 ->val += t2->val;
    }else {
        return t1 != NULL ? t1 : t2;
    }
    
    t1 ->left = mergeTrees(t1->left, t2->left);
    t1 ->right = mergeTrees(t1->right, t2->right);

    return t1;
}


void run617() {
    struct TreeNode *t1 = createTreeByString("[1,3,2,5]");
    struct TreeNode *t2 = createTreeByString("[2,1,3,null,4,null,7]");
    struct TreeNode *t3 = mergeTrees(t1, t2);
    printTree(t3);
}

#pragma mark - TEST

void runEasyPart2() {
//    run617();
//    run561();
//    run476();
    run556();
}

