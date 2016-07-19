//
//  main.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/11/28.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "linked-list.h"

#pragma mark - Leetcode
#include "zigzag-conversion.h"
#include "two-sum.h"
#include "add-two-numbers.h"
#include "longest-substring-without-repeating-characters.h"

#include "string.h"
//#include "median-of-two-sorted-arrays.h"
#include "move-zeroes.h"

#include "valid-anagram.h"

#include "compare-version-numbers.h"

#include "lowest-common-ancestor-of-a-binary-search-tree.h"
#include "reverse-linked-list.h"
#include "remove-duplicates-from-sorted-list.h"
#include "merge-two-sorted-lists.h"

#include "climbing-stairs.h"
#include "remove-element.h"
#include "roman-to-integer.h"
#include "house-robber.h"
#include "remove-duplicates-from-sorted-array.h"


#include "LeetcodeEasyPart.h"


#include "Tree.h"

int main(int argc, const char * argv[]) {
    
    
    //Given binary tree [3,9,20,null,null,15,7],
//    struct TreeNode * convertArrayToBinaryTree(int *input, int size) ;
//[1,2,2,3,4,4,3]
    int input[] = {1,2,3,4,5,6,7};
//    convertArrayToBinaryTree(input, 7);

    struct TreeNode* node =  creatTree(input, 7);
    printOfTree(node);
//    int input[] = {12,31,3,4};
//    int *p = input;
//    for (int i = 0 ; i < 4; i++) {
//        printf("length %d \n", *p);
//        p++;
//    }
    
    
//    testTree123();
    
    runEasyPart();
    
#pragma mark - Leetcode
    //    testZigzag();
    //    testAddTowNumber();
    //    testTwoSum();
    //    sortedArray(10);
    
//    testAnagram();
    
    
    
    //    moveZeroesTest();
    
    //    char *s = "anagram";
    //    char *t = "nagaram";
    //    char *s = "rat";
    //    char *t = "car";
//    testCompareVersion();
//    testLowestCommonAncestor();
    
//    testReverseList();
//    testDeleteDuplicates();
//    testMergeTwoLists();
//    testRemoveElement();
//    testRomanToInt();
//    testHouseRobber();
//    testRemoveDuplicatesFromSortedArray();
    return 0;
}
