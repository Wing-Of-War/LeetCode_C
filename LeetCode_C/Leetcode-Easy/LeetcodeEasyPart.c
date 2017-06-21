 //
//  LeetcodeEasyPart.c
//  LeetCode_C
//
//  Created by JUE DUKE on 7/5/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "LeetcodeEasyPart.h"



#pragma mark - 463. Island Perimeter


int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int result = 0;
    for (int r = 0; r < gridRowSize; r++) {
        for (int c = 0; c < gridColSize; c++) {
            if (grid[r][c]) {
                result += 4;
                if (r > 0 && grid[r-1][c]) {
                    result--;
                }
                if (c > 0 && grid[r][c-1]) {
                    result--;
                }
                if (r < gridRowSize-1 && grid[r+1][c]) {
                    result--;
                }
                if (c <gridColSize-1 && grid[r][c+1]) {
                    result--;
                }
            }
        }
    }
    return result;
}

void run463() {

//    int input4[4][4] ={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
//    int **input = (int **)malloc(sizeof(int *) * 4);
//
//    for (int i = 0; i < 4; i++) {
//        input[i] = input4[i];
//    }


    int input4[1][2] = {{0,1}};
    int **input = (int **)malloc(sizeof(int *) * 1);

    for (int i = 0; i < 1; i++) {
        input[i] = input4[i];
    }
    int size = islandPerimeter(input, 1, 2);
    printf("%d", size);
}


#pragma mark - 448. Find All Numbers Disappeared in an Array
//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
//https://leetcode.com/problems/find-all-duplicates-in-an-array/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    //76ms, not the fastest.
    int *result = (int *)malloc(sizeof(int) * numsSize);
    for (int i =0; i < numsSize; i++) {
        result[i] = -1;
    }
    for (int i = 0; i < numsSize; i++) {
        result[nums[i]-1] = nums[i];
    }
    int size = 0;
    for (int i = 0; i < numsSize; i++) {
        if (result[i] == -1) {
            result[size] = i+1;
            printArray(result, numsSize);
            size++;
        }
    }
    *returnSize = size;
    return result;
}

int cmpfunc3(const void *a, const void *b) {
    if (*(int *)b > *(int *)a) {
        return -1;
    } else if (*(int *)b < *(int *)a ) {
        return 1;
    }
    return 0;  //I can't figure out.
}



void run448() {

    int input[] = {4,3,2,7,8,2,3,1};
    int returnSize = 0;
    int numSize = 8;
    int *result = findDisappearedNumbers(input, numSize, &returnSize);

    printArray(result, returnSize);
}

#pragma mark - 461. Hamming Distance
//https://leetcode.com/problems/hamming-distance/

int hammingDistance(int x, int y) {
    int diff = 0;
    int xx;
    int yy;
    while(x>0||y>0) {
        xx = x%2;
        yy = y%2;
        if (xx != yy) {
            diff ++;
        }
        printf("%d, %d\n", xx, yy);
        x = x/2;
        y = y/2;
    }
    return diff;
}

void run461() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            int distance = hammingDistance(i, j);
            printf("x %d, y %d, dis %d\n", i , j, distance);
        }
    }
}

#pragma mark - 400. Nth Digit

//int timesWith9x(int n) {
//    int result = 9;
//    int times = n;
//    while (times>1) {
//        result *= 10;
//        times --;
//    }
//    return result;
//}
//
//int findNthDigit(int n) {
//
//    int length = 1;
//
//    while (n - timesWith9x(length) * length > 0) {
//        n = n - timesWith9x(length) * length;
//        length++;
//    }
//    int index = n / length;
//
//
//    return 0;
//}
//
//void run400() {
//
//}

#pragma mark - 234. Palindrome Linked List
//https://leetcode.com/problems/palindrome-linked-list/

bool isPalindrome234(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    struct ListNode *fastNode = head;
    struct ListNode *slowNode = head;
    while (fastNode->next && fastNode->next->next) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
    }
    struct ListNode *midNode = slowNode->next;
    midNode = reverseList(midNode);

    bool result = true;
    slowNode = head;
    fastNode = midNode;
    while (fastNode != NULL && slowNode != NULL) {
        if (slowNode == midNode) {
            break;
        }
        if (fastNode->val != slowNode->val) {
            result = false;
            break;
        }
        fastNode = fastNode->next;
        slowNode = slowNode->next;
    }

    return result;
}

#pragma mark - 437. Path Sum III
//https://leetcode.com/problems/path-sum-iii/

int dsfTree(struct TreeNode *root, int sum) {

    int result = 0;
    if (root == NULL) {
        return 0;
    }
    if (sum == root->val) {
        result++ ;
    }
    return result + dsfTree(root->left, sum - root->val) + dsfTree(root->right, sum - root->val);
}

int pathSum(struct TreeNode* root, int sum) {
    if (root == NULL) {
        return 0;
    }

    return dsfTree(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

void run437() {
//    char *inputTree = "[8,8,8,8,8]";
    char *inputTree = "[1,-2,-3,1,3,-2,null,-1]";
    struct TreeNode *root = createTreeByString(inputTree);
    int result = pathSum(root, -1);
    printf("%d ", result);
}


#pragma mark - 453. Minimum Moves to Equal Array Elements   QuestionEditorial Solution


int minMoves(int* nums, int numsSize) {

    int step = 0;

    int max = nums[0];
    int min = nums[0];
    int maxIndex = 0;
    for (int i = 0 ; i < numsSize; i++) {
        if (nums[i] >= max) {
            max = nums[i];
            maxIndex = i;
        }
        if (nums[i] <= min) {
            min = nums[i];
        }
    }
    if (max == min) {
        return step;
    }

    int ori = min;
    while (max != min) {
        for (int i = 0 ; i < numsSize; i++) {
            if (maxIndex != i) {
                nums[i] ++;
            }
            if (nums[i] > max) {
                maxIndex = i;
                max = nums[i];
            }
        }
        min++;
    }

    return min-ori;
}

void run453() {
    int inputs[4] = {1,2,3,4};
    int moves = minMoves(inputs, 4);
//    int inputs[2] = {1,2147483647};
//    int moves = minMoves(inputs, 2);
    printf("%d", moves);
}

#pragma mark - 303. Range Sum Query - Immutable
//https://leetcode.com/problems/range-sum-query-immutable/

//Very slow.


struct NumArray {
    int val;
    int *sum;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    struct NumArray *result = (struct NumArray *)malloc(sizeof(struct NumArray));
    result -> val = numsSize;
    result -> sum = (int *)malloc(sizeof(int) * numsSize + 1);
    result -> sum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        result -> sum[i+1] = result ->sum[i] + nums[i];
    }

    return result;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    if (numArray == NULL) {
        return 0;
    }
    int sum = numArray->sum[j+1] - numArray->sum[i];
    return sum;
}
/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray->sum);
    free(numArray);
}





#pragma mark - 160. Intersection of Two Linked Lists




struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA ==NULL || headB == NULL) {
        return NULL;
    }

    struct ListNode *pa = headA;
    struct ListNode *pb = headB;
    while (pa != pb) {

        if (pa == NULL) {
            pa = headB;
        } else {
            pa = pa->next;
        }
        if (pb == NULL) {
            pb = headA;
        } else {
            pb = pb->next;
        }
    }
    return pa;
}

void run160() {
}

#pragma mark - 414. Third Maximum Number
//https://leetcode.com/problems/third-maximum-number/

int thirdMax(int* nums, int numsSize) {

    qsort(nums, numsSize, sizeof(int32_t), cmpfunc);
    int result = nums[0];
    int index = 0;
    for (int i = 0; i< numsSize; i++) {
        if (result != nums[i]) {
            index ++;
            result = nums[i];
            if (index == 2) {
                break;
            }
        }
    }
    if (index < 2) {
        return nums[0];
    }
    return result;
}

void run414()  {


    int size =  3;
//    int *testArray = randomArray(size, size);
    int testArray[3] = {-2147483648,1,1};
    int result = thirdMax(testArray, size);
    printArray(testArray, size);
    printf("result %d", result);
}

#pragma mark - 38. Count and Say
//https://leetcode.com/problems/count-and-say/

//If use int to setup array , runtime error. We can't malloc enougth memory.
char* intArrayToString(char *nums, size_t size) {
    char *result = (char *)malloc(size);
    for (int i = 0; i < size; i++) {
        result[i] = '0' + nums[i];
    }
    result[size] = '\0';
    return result;
}

char* countAndSay(int n) {
    if (n == 0) {
        return NULL;
    }
    char *s = "1";
    int count = n;
    while (count > 1) {
        int lastStrLength = (int)strlen(s);
        char *container = malloc(lastStrLength * 2);
        int index = 0;
        int times = 1;
        for (int i = 0; i < lastStrLength; i++) {
            if (i + 1 == lastStrLength || s[i] != s[i+1]) {
                container[index] = times;
                container[index + 1] = s[i] - '0';
                index += 2;
                times = 1;
            } else {
                times ++;
            }
        }
        s = intArrayToString(container, index);
        count --;
    }
    return s;
}

void run38() {
    for (int i = 0; i < 31; i++) {
        char *s = countAndSay(i);
        printf("input %d: %s\n",i, s);
    }
}

#pragma mark - 438. Find All Anagrams in a String
//https://leetcode.com/problems/find-all-anagrams-in-a-string/

bool compareIntArray(int *g1, int *g2, int *pos, int type) {
    bool same = true;
    for (int i = 0 ; i < type; i++) {
        int p = pos[i];
        if (g1[p] != g2[p]) {
            same = false;
        }
    }
    return same;
}

int* findAnagrams(char* s, char* p, int* returnSize) {
    //Very slow. bad answer.
    if (s == NULL) {
        return NULL;
    }

    int c[26] = {0};
    char *t = p;
    int lengthP = 0;
    int pos[26] = {0};
    int type = 0;
    while (*t) {
        c[*t-'a'] ++;
        if (c[*t-'a']==1) {
            pos[type] = *t-'a';
            type ++;
        }
        lengthP ++;
        t++;
    }
    t = s;
    int lengthS = 0;
    while (*t) {
        lengthS ++;
        t++;
    }
    if (lengthS < lengthP) {
        return NULL;
    }

    int c2[26] = {0};
    int length = lengthP;
    while (length) {
        c2[s[length-1] - 'a'] ++;
        length--;
    }

    int *result = (int *)malloc(sizeof(int) * 20100);
    int size = 0;
    if (compareIntArray(c, c2, pos, type)) {
        result[size] = 0;
        size ++;
    }

    char *lastS = s+lengthP;
    char *startS = s;
    int index = 0;
    while (*lastS) {
        index++;
        c2[*lastS - 'a'] ++;
        c2[*startS - 'a'] --;
        if (compareIntArray(c, c2, pos, type)) {
            result[size] = index;
            size ++;
        }
        lastS++;
        startS++;
    }
    *returnSize = size;
    return result;
}

void run438() {

    char *s = "cbaebabacd";   char *p = "abc";
//    char *s = "abab";   char *p ="ab";

//    char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";    char *p = "a";

    int returnSize = 0;
    int *result = findAnagrams(s, p, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d, ", result[i]);
    }
}

#pragma mark - 405. Convert a Number to Hexadecimal
//https://leetcode.com/problems/convert-a-number-to-hexadecimal/

char* toHex(int num) {
    if (num==0) {
        return "0";
    }

    int size = 0;
    unsigned int t = num;
    while (t > 0) {
        size ++;
        t /= 16;
    }
    t = num;
    char *result = (char *)malloc(size);
    result[size] = '\0';
    while (t > 0) {
        char value = t % 16;
        if (value < 10) {
            result[--size] = value + '0';
        } else {
            result[--size] = value + 'a' - 10;
        }
        t /= 16;
    }
    return result;
}

void run405(){
    for (int i = -16; i > -100; i--) {
        printf("input: %d -> %s\n",i, toHex(i));
    }

//    unsigned int i = -2;
//    printf("%x", i);
//    int j = -2;
//    printf("%x", j);
}

#pragma mark - 83. Remove Duplicates from Sorted List
//https://leetcode.com/problems/remove-duplicates-from-sorted-list/

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return numsSize;
    }

    int duplicateCount = 0;
    int lastNum = nums[0];
    //    for (int i = 1 ; i < numsSize; i++) {
    //        if(nums[i] == lastNum) {
    //            duplicateCount++;
    //            continue;
    //        }
    //        nums[i-duplicateCount] = nums[i];
    //        lastNum = nums[i];
    //    }

    //Faster than continue.
    for (int i = 1 ; i < numsSize; i++) {
        if(nums[i] == lastNum) {
            duplicateCount++;
        } else {
            nums[i-duplicateCount] = nums[i];
            lastNum = nums[i];
        }
    }
    return numsSize - duplicateCount;
}


void testRemoveDuplicatesFromSortedArray(void) {
    //    int *nums = sortedArray(10);
    const int size = 10;
    int nums[size] = {1,1,1,2,2,2,3,3,3,3};
    printArray(nums, size);
    int length = removeDuplicates(nums, size);
    printArray(nums, length);
}




#pragma mark - 198. House Robber
//https://leetcode.com/problems/house-robber



int rob(int* nums, int numsSize) {
    int odd = 0,even = 0;
    for (int i = 0 ; i < numsSize ; i++) {
        if (i%2) {
            int value = odd + nums[i];
            odd = value > even ? value : even;
        } else {
            int value = even + nums[i];
            even = value > odd ? value : odd;
        }
    }
    return odd>even?odd:even;
}


void run198(void) {
    int nums[100] = {226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};

    int size = 0;
    while (1) {
        if (nums[size] == 124) {
            break;
        }
        size ++;
    }

    //    int size = sizeof(nums)/sizeof(int);
    int result = rob(nums, size);
    printf("result %d", result);
}

#pragma mark - 100. Same Tree
//https://leetcode.com/problems/same-tree/

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

#pragma mark - 237. Delete Node in a Linked List
//https://leetcode.com/problems/delete-node-in-a-linked-list/

void deleteNode(struct ListNode* node) {
    struct ListNode* nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    free(nextNode);
}

#pragma mark - 258. Add Digits
//https://leetcode.com/problems/add-digits/

int addDigits(int num) {

    if (num) {
        int result = num % 9;
        return result ? result : 9;
    }
    return 0;
}

#pragma mark - 292. Nim Game
//https://leetcode.com/problems/nim-game

bool canWinNim(int n) {
    return n%4;
}

#pragma mark - 13. Roman to Integer
//https://leetcode.com/problems/roman-to-integer

int convertRomanCharToInt(char romanChar) {
    switch (romanChar) {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
            break;
    }
}

int romanToInt(char* s) {
    int result = 0;
    int groupSum = 0;
    int lastValue = 0;
    char *t = s;
    while (*t != '\0') {
        char romanValue = *t;
        t++;
        int value = convertRomanCharToInt(romanValue);
        if (lastValue == 0) {
            lastValue = value;
            groupSum = value;
            continue;
        }
        if (value == lastValue) {
            groupSum += value;
        }
        if (value > lastValue) {
            result = result - groupSum + value;
            groupSum = 0;
        }

        if (value < lastValue) {
            result += groupSum;
            groupSum = value;
        }
        lastValue = value;
    }
    result += groupSum;

    return result;
}

void run13(void) {
    //    char *s = "MCD";
    //    char *s = "LXXX";
    //    char *s = "MDCCCLXXXIV";
    char *s = "CMLII";
    int value = romanToInt(s);
    printf("Roman Value: %d", value);

}

#pragma mark - 169. Majority Element
//https://leetcode.com/problems/majority-element/

int majorityElement(int* nums, int numsSize) {
    int result = 0;
    int count = 0;
    for(int i = 0; i<numsSize; i++) {
        if(count == 0) {
            result = nums[i];
            count ++;
        } else {
            int number = nums[i];
            if (number == result) {
                count ++;
            } else {
                count --;
            }
        }
    }
    return result;
}

#pragma mark - 27. Remove Element
//https://leetcode.com/problems/remove-element/

int removeElement(int* nums, int numsSize, int val) {
    int duplicateCount = 0;
    for (int i = 0 ; i < numsSize - duplicateCount;) {
        if (nums[i] != val) {
            i++;
            continue;
        }
        for (int j = i; j < numsSize - duplicateCount - 1; j++) {
            nums[j] = nums[j+1];
        }
        duplicateCount++;
    }
    return numsSize - duplicateCount;
}


void run27(void) {
    int nums[] = {1,2,3,4,5,6,6,7};
    int size = sizeof(nums) / sizeof(int);
    int length = removeElement(nums, size, 6);
    printArray(nums, size);
    printf("length %d", length);
}

#pragma mark - 110. Balanced Binary Tree
//https://leetcode.com/problems/balanced-binary-tree/

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





#pragma mark - 21. Merge Two Sorted Lists
//https://leetcode.com/problems/merge-two-sorted-lists/



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;

    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    struct ListNode *result = NULL;
    struct ListNode *head = NULL;

    while (p1 && p2) {
        int value1 = p1->val;
        int value2 = p2->val;
        struct ListNode *t =  value1 > value2 ? p2 : p1;
        if (value1 > value2) {
            p2 = p2->next;
        } else {
            p1 = p1->next;
        }

        if (result) {
            result->next = t;
            result = result->next;
        } else {
            result = t;
            head = t;
        }

    }
    if (p1 == NULL) {
        result->next = p2;
    } else {
        result->next = p1;
    }

    return head;
}

void run21() {
    int *nums1 = sortedArray(4);
    int *nums2 = sortedArray(6);
    struct ListNode *node1 = createLinkList(nums1, 4);
    struct ListNode *node2 = createLinkList(nums2, 6);
    struct ListNode *node3 = mergeTwoLists(node1, node2);
    printLinkList(node3);
}


#pragma mark - 70. Climbing Stairs
//https://leetcode.com/problems/climbing-stairs/

int climbStairs(int n) {
    if (n<3) {
        return n;
    }

    int *keep = (int *)malloc(sizeof(int) * n);
    keep[0] = 1;
    keep[1] = 2;

    int i = 2;
    int sum = 0;
    while (i < n) {
        sum = keep[i-1] + keep[i-2];
        keep[i] = sum;
        i++;
    }
    return sum;
}

void run70() {
    for (int i = 1 ; i < 45; i++) {
        int result = climbStairs(i);
        printf("input %d result %d \n", i, result);
    }
}

#pragma mark - 83. Remove Duplicates from Sorted List
//https://leetcode.com/problems/remove-duplicates-from-sorted-list/

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *temp = head;
    if (temp == NULL) {
        return NULL;
    }
    while (temp->next) {
        struct ListNode *t = NULL;
        if (temp->val == temp->next->val) {
            t = temp->next;
            temp->next = t->next;
        } else {
            temp = temp->next;
        }


        //with free 8.00ms. without 4.00ms
        if (t) {
            free(t);
        }
    }

    return head;
}


void run83() {

    int nums[] = {1,1,2,3,3};
    struct ListNode *list = createLinkList(nums, 5);
    printLinkList(deleteDuplicates(list));

    //    int nums[] = {1};
    //    struct ListNode *list = createLinkList(nums, 1);
    //    showLinkList(deleteDuplicates(list));

    //    int nums[] = {};
    //    struct ListNode *list = createLinkList(nums, 0);
    //    showLinkList(deleteDuplicates(list));

    //    int nums[] = {1,1,1,1,1};
    //    struct ListNode *list = createLinkList(nums, 5);
    //    showLinkList(deleteDuplicates(list));

}


#pragma mark - 206. Reverse Linked List
//https://leetcode.com/problems/reverse-linked-list/


void run206(void) {
    const int size = 6;
    int input[size] = {1,2,3,4,5,6};
    struct ListNode *node = createLinkList(input, size);
    struct ListNode *reversList = reverseList(node);
    printLinkList(reversList);
}


#pragma mark - 235. Lowest Common Ancestor of a Binary Search Tree
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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

void run235(void) {
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

#pragma mark - 165. Compare Version Numbers
//https://leetcode.com/problems/compare-version-numbers/

int compareVersion(char* version1, char* version2) {
    int value1 = 0;
    int value2 = 0;

    char *p1 = version1;
    while (*p1 != '.' && *p1 != '\0') {
        value1 = value1 * 10 + *p1 - '0';
        p1++;
    }

    char *p2 = version2;
    while (*p2 != '.' && *p2 !='\0') {
        value2 = value2 * 10 + *p2 - '0';
        p2++;
    }

    if (value1 == value2) {
        if (*p1 =='\0' && *p2 == '\0') {
            return 0;
        } else {
            if (*p1 == '.') {
                p1++;
            }
            if (*p2 == '.') {
                p2++;
            }
            return compareVersion(p1, p2);
        }
    } else if (value1 > value2) {
        return 1;
    } else {
        return -1;
    }
}




void run165(void) {

    //    int result = compareVersion("0.1.1", "0.2.1");
    //    printf("result %d", result);

    //    int result = compareVersion("1", "1.1");
    //    printf("result %d", result);

    //    int result = compareVersion("01", "1");
    //    printf("result %d", result);

    int result = compareVersion("1.0", "1");
    printf("result %d", result);

}

#pragma mark - 242. Valid Anagram
//https://leetcode.com/problems/valid-anagram/

bool isAnagram(char* s, char* t) {
    int count1[26] = {0};
    int count2[26] = {0};

    char *p = s;
    while (*p != '\0') {
        count1[*p - 'a']++;
        p++;
    }
    p = t;
    while (*p != '\0') {
        count2[*p - 'a']++;
        p++;
    }
    for (int i = 0 ; i < 26 ; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }

    return true;
}

void run242(void) {

    //    char *s = "anagram";
    //    char *t = "nagaram";

    char *s = "";
    char *t = "";
    bool result = isAnagram(s, t);
    printf("result %d", result);
}

#pragma mark - 171. Excel Sheet Column Number
//https://leetcode.com/problems/excel-sheet-column-number/

int titleToNumber(char* s) {
    int result = 0;
    while(*s != '\0') {
        int value = *s - 'A' + 1;
        result = result * 26 + value;
        s++;
    }
    return result;
}

#pragma mark - 263. Ugly Number
//https://leetcode.com/problems/ugly-number

bool isUgly(int num) {
    if (num <= 0) {
        return false;
    }

    if (num % 2 == 0) {
        return isUgly(num/2);
    }
    if (num % 3 == 0) {
        return isUgly(num/3);
    }
    if (num % 5 == 0) {
        return isUgly(num/5);
    }
    if (num == 1) {
        return true;
    } else {
        return false;
    }
}

#pragma mark - 326. Power of Three
//https://leetcode.com/problems/power-of-four/

//Slow.

bool isPowerOfThree(int n) {
//    0: true true 1
//    1: true true 3
//    2: true false 9
//    3: true false 27
//    4: true false 81
//    5: false true 243
//    6: true false 729
//    7: true false 2187
//    8: true false 6561
//    9: true false 19683
//    10: false true 59049
//    11: true false 177147
//    12: true false 531441
//    13: false false 1594323
//    14: true false 4782969
//    15: false false 14348907
//    16: true false 43046721
//    17: false true 129140163
//    18: true false 387420489
//    19: true false 1162261467

    //Fastest. 	46 ms, beat all commit in C.
    int threes[] = {1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467};
    for (int i = 0; i < 20; i++) {
        if (threes[i] == n) {
            return true;
        }
    }
    return false;

    //Slow.  112 ms
//    double result =  log(n)/log(3.0);
//    double rest = result -  round(result) ;
//    if (fabs(rest) < 1e-13) {
//        return true;
//    }
//    return false;
}

#pragma mark - 342. Power of Four
//https://leetcode.com/problems/power-of-four/

bool isPowerOfFour(int num) {
    double result = log(num)/ log (4);
    double rest = result - round(result);
    if (fabs(rest) < 1e-13) {
        return true;
    }
    return false;

}
#pragma mark - 231. Power of Two
//https://leetcode.com/problems/power-of-two/

bool isPowerOfTwo(int n) {

//    double result = log(n)/ log (2);
//    double rest = result - round(result);
//    if (fabs(rest) < 1e-13) {
//        return true;
//    }
//    return false;

    if(n==0 || n < 0) {
        return false;
    }
    if(n==1 || n==2) {
        return true;
    }
    int t = n;
    while(t>2) {
        int rest = t % 2;
        if (rest) {
            return false;
        }
        t=t/2;
    }
    return true;
}

#pragma mark - 6. ZigZag Conversion
//https://leetcode.com/problems/zigzag-conversion/

char* convert(char* s, int numRows) {
    long length = strlen(s);
    char * r = (char *)malloc(sizeof(char) * length);
    int space = (numRows -1) * 2;
    if (space == 0) {
        space = 1;
    }
    long resIndex = 0;
    long oriIndex = 0;
    int row = 0;
    int restSpace = space - (row * 2);
    while (resIndex <= length) {
        r[resIndex] = s[oriIndex];
        resIndex++;
        if (restSpace == 0) {
            restSpace = space;
        }
        oriIndex += restSpace;
        if (oriIndex > length-1) {
            row ++;
            oriIndex = row;
            restSpace = space - (row * 2);
            continue;
        }
        restSpace = space - restSpace;
    }
    r[length] = '\0';

    return r;
}

void run6(void) {
    //    "glzamzp"
    //    5
    char * inputString = "glzamzp";
    char * sp = inputString;
    while (*sp !='\0') {
        putchar(*sp);
        sp++;
    }

    putchar('\n');
    char * r = convert(inputString,  5);
    puts(r);

}

#pragma mark - 441. Arranging Coins
//https://leetcode.com/problems/arranging-coins/

int arrangeCoins(int n) {

//    x|2 + x - 2n = 0;

    //Slow 9ms & need use double.
//    unsigned long delt = 1.0 + 8.0 * (unsigned long)n;
//    double stdDelt = sqrtl(delt);
//    double x1 = (stdDelt - 1 ) / 2;
//    int result = (int)x1;
//    printf("input:%d,  %d\n",n, result);

    //Faster 6ms & clear.
    int result = (int)(sqrt(2.0 * n + 0.25)-0.5);
    printf("input:%d,  %d\n",n, result);
    return result;
}

void run441() {
    for (int i = 0 ; i < 100; i ++) {
        arrangeCoins(i);
    }

//    arrangeCoins(1804289383);
    arrangeCoins(2146467959);

}

#pragma mark - 191. Number of 1 Bits
//https://leetcode.com/problems/number-of-1-bits/

int hammingWeight(uint32_t n) {
    int result = 0;
    while (n > 0) {
        int temp = n % 2;
        if (temp == 1) {
            result ++;
        }
        n = n/2;
    }
    return result;
}

void run191() {
//    00000000000000000000000000001011
}

#pragma mark - 283. Move Zeroes
//https://leetcode.com/problems/move-zeroes/

void moveZeroes(int* nums, int numsSize) {
    int currentZeroCount = 0;
    int currentIndex = 0;
    while (currentIndex < numsSize) {
        if (nums[currentIndex]) {
            nums[currentIndex-currentZeroCount] = nums[currentIndex];
        } else {
            currentZeroCount ++;
        }
        currentIndex++;
    }
    currentIndex = numsSize - currentZeroCount;
    while (currentIndex < numsSize) {
        nums[currentIndex]=0;
        currentIndex++;
    }
}

void run283() {
    int arraySize = 10;
    int *input = randomArray(arraySize, 10);

    input[1] = 0;
    input[5] = 0;
//    outputArray(input, arraySize);
    moveZeroes(input, arraySize);
//    outputArray(input, arraySize);
}

#pragma mark - 226. Invert Binary Tree
//https://leetcode.com/problems/invert-binary-tree/

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

#pragma mark - 217. Contains Duplicate
//https://leetcode.com/problems/contains-duplicate/



bool containsDuplicate(int* nums, int numsSize) {
    //Slow way.
//    int currentIndex = 0;
//    while(currentIndex < numsSize) {
//        for(int i = 0; i < currentIndex; i++) {
//            if (nums[i] == nums[currentIndex]) {
//                return true;
//            }
//        }
//        currentIndex ++;
//    }

//    qsort(nums, numsSize, sizeof(int), cmpfunc);

    for (int i = 0; i< numsSize-1; i++) {
        if (nums[i] == nums[i+1]) {
            return true;
        }
    }
    return false;
}

void run217() {
//    int size = 100;
//    int *array = randomArray(size,size);
    int array[2] = {3,3};
    int size = 2;
    bool result = containsDuplicate(array, size);
    printf("%d", result);
}

#pragma mark - 257. Binary Tree Paths

typedef struct StringNode{
    char *content;
    struct StringNode *nextNode;
}Snode;

Snode *newSnode() {
    Snode *node = (Snode *)malloc(sizeof(Snode *));
    node->content = NULL;
    node->nextNode = NULL;
    return node;
}

void nextTreeNode(struct TreeNode *root, char *inputString, Snode *head) {
    char str[15];
    if (root->left == NULL && root->right == NULL) {
        sprintf(str, "%d", root->val);
    } else {
        sprintf(str, "%d->", root->val);
    }
    char * new_str;
    if((new_str = malloc(strlen(inputString)+strlen(str)+1)) != NULL){
        new_str[0] = '\0';   // ensures the memory is an empty string
        strcat(new_str,inputString);
        strcat(new_str,str);
    }
    if (root->left || root->right) {
        if (root->left) {
            nextTreeNode(root->left, new_str, head);
        }
        if (root->right) {
            nextTreeNode(root->right, new_str, head);
        }
    } else {
        if (head->content == NULL) {
            head->content = new_str;
        } else {
            Snode *t = head;
            while (t->nextNode) {
                t = t->nextNode;
            }
            Snode *node = newSnode();
            node->content = new_str;
            t->nextNode = node;
        }
    }
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    if (root==NULL) {
        return NULL;
    }
    char *temp = "";
    Snode *node = newSnode();
    nextTreeNode(root, temp, node);
    Snode *t = node;
    //    int size = 0;
    //    while (t) {
    //        t = t->nextNode;
    //        size++;
    //    }
    char **result = (char **)malloc(sizeof(char *) * 1000);
    int index = 0;
    t = node;
    while (t) {
        result[index] = t->content;
        t = t->nextNode;
        index++;
    }
    *returnSize = index;
    return result;
}



void run257() {
//    struct TreeNode *node = createTreeByString("[1,2,3,4,5]");
//    struct TreeNode *node = createTreeByString("[1,2,3,null,5]");
//    struct TreeNode *node = createTreeByString("[]");
    struct TreeNode *node = createTreeByString("[1,null,2]");
    int returnSize = 0;
    char **result = binaryTreePaths(node, &returnSize);
    for (int i = 0 ; i< returnSize; i++) {
        printf("%s\n", result[i]);
    }
}


#pragma mark - 415. Add Strings

char* addStrings(char* num1, char* num2) {
    int l1 = (int)strlen(num1);
    int l2 = (int)strlen(num2);
    int length = l1>l2 ? l1 : l2;
    char *result = (char *)malloc(length + 2);
    result[length + 1] = '\0';
    int step = 0;
    for (int i = 0; i < length; i++) {
        int v1 = 0;
        int v2 = 0;
        if(l1) {
            v1 = num1[--l1] - '0';
        }
        if(l2) {
            v2 = num2[--l2] - '0';
        }
        int v3 = v1 + v2 + step;
        if(v3>=10) {
            v3 = v3 % 10;
            step = 1;
        } else {
            step = 0;
        }
        int pos = length - i;
        result[pos] = v3 + '0';
    }
    if (step) {
        result[0] = 1 + '0';
    } else {
        result ++;
    }
    return result;
}

void run415() {
//    "6913259244"
//    "71103343"

//    char *result = addStrings("2312", "12");
//    char *result = addStrings("6913259244", "71103343");
    char *result = addStrings("1", "9");
    printf("%s",result);
}

#pragma mark - 401. Binary Watch
//https://leetcode.com/problems/binary-watch/
//
//char* convertPositionToString(int position[]) {
//    int value[10] = {8,4,2,1,32,16,8,4,2,1};
//    int min = 0;
//    int hour = 0;
//
//    for (int i = 0; i < 10; i++) {
//        if (position[i]) {
//            if (i < 4) {
//                hour = hour + value[i];
//            } else {
//                min = min + value[i];
//            }
//        }
//    }
//    if (hour > 12 || min > 60) {
//        printf("ERROR\n");
//        return NULL;
//    }
//
//    char *result = (char *)malloc(sizeof(char ) * 6);
//    result[0] = '\0';
//    if (min < 10) {
//        sprintf(result, "%d:0%d\n", hour, min);
//    } else {
//        sprintf(result, "%d:%d\n", hour, min);
//    }
//    printf("%s", result);
//    return result;
//}
//
//void travelTime(int count,int start, int *position, int **result) {
//    if (count == 0) {
////        for(int i = 0; i < 10; i++) {
////            printf("%d", position[i]);
////        }
////        printf("\n");
////        char *s = convertPositionToString(position);
//        int *temp = *result;
//        while (temp) {
//            temp ++;
//        }
//        temp = position;
//        return;
//    }
//    for (int i = start ; i < 10; i++) {
//        if (position[i] == 0) {
//            int *newPos = (int *)malloc(sizeof(int) * 10);
//            for (int i = 0 ; i < 10; i++) {
//                newPos[i] = position[i];
//            }
//            newPos[i] = 1;
//            travelTime(count-1, i+1, newPos,result);
//        }
//    }
//}
//
//int getSizeByC10(int num) {
//    int result = 1;
//    if (num == 0) {
//        return 1;
//    }
//    int n = 0;
//    int factor = 10;
//    while (n < num) {
//        result *= factor;
//        factor--;
//        n ++;
//        result /= n;
//    }
//    return result;
//}
//
//char** readBinaryWatch(int num, int* returnSize) {
//    int pos[10] = {0};
//    int size = getSizeByC10(num);
//    int **positions = (int **)malloc((sizeof(int *) * size));
//
//    travelTime(num, 0, pos, positions);
//
//    for(int i = 0; i < size; i++) {
//        int *position = positions[i];
//        for (int j = 0 ; j < 10; j++) {
//            printf("%d", position[i]);
//        }
//    }
//    printf("\n");
////    char *s = convertPositionToString(position);
//
////    char **result =
//    return NULL;
//}

char** readBinaryWatch(int num, int* returnSize) {

    int hourc[4] = {
        1,4,5,2
    };
    int hours[4][6] = {
        {0},
        {1,2,4,8},
        {3,5,6,9,10},
        {7,11}
    };
    int minc[6] = {
        1,6,15,20,14,4
    };
    int mins[6][20] = {
        {0},
        {1,2,4,8,16,32},
        {3,5,6,9,10,12,17,18,20,24,33,34,36,40,48},
        {7,11,13,14,19,21,22,25,26,28,35,37,38,41,42,44,49,50,52,56},
        {15,23,27,29,30,39,43,45,46,51,53,54,57,58},
        {31,47,55,59}
    };

    int count = 0;
    for (int i = 0; i < 4 && i <= num; i++) {
        if (num - i <= 5) {
            int hourcc = hourc[i];
            int mincc = minc[num-i];
            count += (mincc * hourcc);
        }
    }
    char **result = (char **)malloc(sizeof(char *) * count);
    int index = 0;
    for (int i = 0; i < 4 && i <= num; i++) {
        if (num - i <= 5) {
            int* hourca = hours[i];
            int* minca = mins[num-i];
            int hourcc = hourc[i];
            int mincc = minc[num-i];
            for (int h = 0 ; h < hourcc; h++) {
                int hour = hourca[h];
                for (int m = 0; m < mincc; m++) {
                    int min = minca[m];
                    char *input = (char *)malloc(6);
                    input[0] = '\0';
                    if(min < 10) {
                        sprintf(input, "%d:0%d", hour, min);
                    } else {
                        sprintf(input, "%d:%d", hour, min);
                    }
//                    printf("%s", input);
//                    printf("\n");
                    result[index] = input;
                    index++;
                }
            }
        }
    }
    *returnSize = count;
    return result;
}

void run401() {
    int size;
    char **result = readBinaryWatch(3, &size);

    for (int i = 0; i < size; i ++) {
        char *str = result[i];
        printf("%s\n", str);
    }
//    long result = getSizeByC10(6);
//    printf("%ld", result);
}

#pragma mark - 409. Longest Palindrome
//https://leetcode.com/problems/longest-palindrome/

int longestPalindrome(char* s) {
    int count[52] = {0};
    int length = (int)strlen(s);
    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (c >= 'a') {
            count[c-'a' + 26]++;
        } else {
            count[c-'A']++;
        }
    }
    int maxL = 0;
    bool haveOdd = false;
    for (int i = 0; i < 52; i++) {
        if (count[i]%2 == 1) {
            maxL += (count[i] -1);
            haveOdd = true;
        } else {
            maxL += count[i];
        }
    }
    if (haveOdd) {
        maxL += 1;
    }
    return maxL;
}

void run409() {
    char *s= "ymbgaraibkfmvocpizdydugvalagaivdbfsfbepeyccqfepzvtpyxtbadkhmwmoswrcxnargtlswqemafandgkmydtimuzvjwxvlfwlhvkrgcsithaqlcvrihrwqkpjdhgfgreqoxzfvhjzojhghfwbvpfzectwwhexthbsndovxejsntmjihchaotbgcysfdaojkjldprwyrnischrgmtvjcorypvopfmegizfkvudubnejzfqffvgdoxohuinkyygbdzmshvyqyhsozwvlhevfepdvafgkqpkmcsikfyxczcovrmwqxxbnhfzcjjcpgzjjfateajnnvlbwhyppdleahgaypxidkpwmfqwqyofwdqgxhjaxvyrzupfwesmxbjszolgwqvfiozofncbohduqgiswuiyddmwlwubetyaummenkdfptjczxemryuotrrymrfdxtrebpbjtpnuhsbnovhectpjhfhahbqrfbyxggobsweefcwxpqsspyssrmdhuelkkvyjxswjwofngpwfxvknkjviiavorwyfzlnktmfwxkvwkrwdcxjfzikdyswsuxegmhtnxjraqrdchaauazfhtklxsksbhwgjphgbasfnlwqwukprgvihntsyymdrfovaszjywuqygpvjtvlsvvqbvzsmgweiayhlubnbsitvfxawhfmfiatxvqrcwjshvovxknnxnyyfexqycrlyksderlqarqhkxyaqwlwoqcribumrqjtelhwdvaiysgjlvksrfvjlcaiwrirtkkxbwgicyhvakxgdjwnwmubkiazdjkfmotglclqndqjxethoutvjchjbkoasnnfbgrnycucfpeovruguzumgmgddqwjgdvaujhyqsqtoexmnfuluaqbxoofvotvfoiexbnprrxptchmlctzgqtkivsilwgwgvpidpvasurraqfkcmxhdapjrlrnkbklwkrvoaziznlpor";
    int length = longestPalindrome(s);
    printf("%d\n", length);
}

#pragma mark - 387. First Unique Character in a String

int firstUniqChar(char* s) {
    int length = (int)strlen(s);
    int index = 0;

    int count[26] ={0};


    for (; index < length; index++) {
        char c = s[index];
        int i = c - 'a';
        count[i]++;
    }
    int position = -1;
    for (index = 0; index < length; index++) {
        char c = s[index];
        int i = c - 'a';
        if(count[i] == 1) {
            position = index;
            break;
        }
    }
    return position;
}

void run387() {
//    char *s = "z";
        char *s = "leetcode";
//        char *s = "loveleetcode";
    int pos = firstUniqChar(s);
    printf("%d", pos);

}


#pragma mark - 383. Ransom Note

bool canConstruct(char* ransomNote, char* magazine) {
    char *p1 = ransomNote;
    char *p2 = magazine;
    int sc[26] = {0};
    int tc[26] = {0};


    while (*p1) {
        sc[*p1-'a'] ++;
        p1++;
    }


    while (*p2) {
        tc[*p2-'a'] ++;
        p2++;
    }

    bool result = true;
    for (int index = 0; index < 26; index++) {
        if (sc[index] > tc[index]) {
            result = false;
            break;
        }
    }

    return result;
}

void run383() {
    char *s= "ymbgaraibkfmvocpizdydugvalagaivdbfsfbepeyccqfepzvtpyxtbadkhmwmoswrcxnargtlswqemafandgkmydtimuzvjwxvlfwlhvkrgcsithaqlcvrihrwqkpjdhgfgreqoxzfvhjzojhghfwbvpfzectwwhexthbsndovxejsntmjihchaotbgcysfdaojkjldprwyrnischrgmtvjcorypvopfmegizfkvudubnejzfqffvgdoxohuinkyygbdzmshvyqyhsozwvlhevfepdvafgkqpkmcsikfyxczcovrmwqxxbnhfzcjjcpgzjjfateajnnvlbwhyppdleahgaypxidkpwmfqwqyofwdqgxhjaxvyrzupfwesmxbjszolgwqvfiozofncbohduqgiswuiyddmwlwubetyaummenkdfptjczxemryuotrrymrfdxtrebpbjtpnuhsbnovhectpjhfhahbqrfbyxggobsweefcwxpqsspyssrmdhuelkkvyjxswjwofngpwfxvknkjviiavorwyfzlnktmfwxkvwkrwdcxjfzikdyswsuxegmhtnxjraqrdchaauazfhtklxsksbhwgjphgbasfnlwqwukprgvihntsyymdrfovaszjywuqygpvjtvlsvvqbvzsmgweiayhlubnbsitvfxawhfmfiatxvqrcwjshvovxknnxnyyfexqycrlyksderlqarqhkxyaqwlwoqcribumrqjtelhwdvaiysgjlvksrfvjlcaiwrirtkkxbwgicyhvakxgdjwnwmubkiazdjkfmotglclqndqjxethoutvjchjbkoasnnfbgrnycucfpeovruguzumgmgddqwjgdvaujhyqsqtoexmnfuluaqbxoofvotvfoiexbnprrxptchmlctzgqtkivsilwgwgvpidpvasurraqfkcmxhdapjrlrnkbklwkrvoaziznlpor";

    char *t = "qhxepbshlrhoecdaodgpousbzfcqjxulatciapuftffahhlmxbufgjuxstfjvljybfxnenlacmjqoymvamphpxnolwijwcecgwbcjhgdybfffwoygikvoecdggplfohemfypxfsvdrseyhmvkoovxhdvoavsqqbrsqrkqhbtmgwaurgisloqjixfwfvwtszcxwktkwesaxsmhsvlitegrlzkvfqoiiwxbzskzoewbkxtphapavbyvhzvgrrfriddnsrftfowhdanvhjvurhljmpxvpddxmzfgwwpkjrfgqptrmumoemhfpojnxzwlrxkcafvbhlwrapubhveattfifsmiounhqusvhywnxhwrgamgnesxmzliyzisqrwvkiyderyotxhwspqrrkeczjysfujvovsfcfouykcqyjoobfdgnlswfzjmyucaxuaslzwfnetekymrwbvponiaojdqnbmboldvvitamntwnyaeppjaohwkrisrlrgwcjqqgxeqerjrbapfzurcwxhcwzugcgnirkkrxdthtbmdqgvqxilllrsbwjhwqszrjtzyetwubdrlyakzxcveufvhqugyawvkivwonvmrgnchkzdysngqdibhkyboyftxcvvjoggecjsajbuqkjjxfvynrjsnvtfvgpgveycxidhhfauvjovmnbqgoxsafknluyimkczykwdgvqwlvvgdmufxdypwnajkncoynqticfetcdafvtqszuwfmrdggifokwmkgzuxnhncmnsstffqpqbplypapctctfhqpihavligbrutxmmygiyaklqtakdidvnvrjfteazeqmbgklrgrorudayokxptswwkcircwuhcavhdparjfkjypkyxhbgwxbkvpvrtzjaetahmxevmkhdfyidhrdeejapfbafwmdqjqszwnwzgclitdhlnkaiyldwkwwzvhyorgbysyjbxsspnjdewjxbhpsvj";

    bool r = canConstruct(s, t);
    printf(" %d ", r);
}

#pragma mark - 404. Sum of Left Leaves
//https://leetcode.com/problems/sum-of-left-leaves/

int sumOfLeftLeaves(struct TreeNode* root) {


    if (root == NULL) {
        return 0;
    }
    int sum = 0;
    if (root->left && root->left->left == NULL && root->left->right == NULL) {
        sum += root->left->val;
    }
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

void run404() {
    struct TreeNode *root = createTreeByString("[0,2,4,1,null,3,-1,5,1,null,6,null,8]");
    int sum = sumOfLeftLeaves(root);
    printf("%d", sum);
}

#pragma mark - 389. Find the Difference

char findTheDifference(char* s, char* t) {
    char *p1 = s;
    char *p2 = t;
    int sc[26] = {0};
    int tc[26] = {0};


    while (*p1) {
        sc[*p1-'a'] ++;
        p1++;
    }


    while (*p2) {
        tc[*p2-'a'] ++;
        p2++;
    }

    int index = 0;
    for (; index < 26; index++) {
        if (sc[index] != tc[index]) {
            break;
        }
    }

    return 'a' + index;
}

void run389() {
    char *s= "ymbgaraibkfmvocpizdydugvalagaivdbfsfbepeyccqfepzvtpyxtbadkhmwmoswrcxnargtlswqemafandgkmydtimuzvjwxvlfwlhvkrgcsithaqlcvrihrwqkpjdhgfgreqoxzfvhjzojhghfwbvpfzectwwhexthbsndovxejsntmjihchaotbgcysfdaojkjldprwyrnischrgmtvjcorypvopfmegizfkvudubnejzfqffvgdoxohuinkyygbdzmshvyqyhsozwvlhevfepdvafgkqpkmcsikfyxczcovrmwqxxbnhfzcjjcpgzjjfateajnnvlbwhyppdleahgaypxidkpwmfqwqyofwdqgxhjaxvyrzupfwesmxbjszolgwqvfiozofncbohduqgiswuiyddmwlwubetyaummenkdfptjczxemryuotrrymrfdxtrebpbjtpnuhsbnovhectpjhfhahbqrfbyxggobsweefcwxpqsspyssrmdhuelkkvyjxswjwofngpwfxvknkjviiavorwyfzlnktmfwxkvwkrwdcxjfzikdyswsuxegmhtnxjraqrdchaauazfhtklxsksbhwgjphgbasfnlwqwukprgvihntsyymdrfovaszjywuqygpvjtvlsvvqbvzsmgweiayhlubnbsitvfxawhfmfiatxvqrcwjshvovxknnxnyyfexqycrlyksderlqarqhkxyaqwlwoqcribumrqjtelhwdvaiysgjlvksrfvjlcaiwrirtkkxbwgicyhvakxgdjwnwmubkiazdjkfmotglclqndqjxethoutvjchjbkoasnnfbgrnycucfpeovruguzumgmgddqwjgdvaujhyqsqtoexmnfuluaqbxoofvotvfoiexbnprrxptchmlctzgqtkivsilwgwgvpidpvasurraqfkcmxhdapjrlrnkbklwkrvoaziznlpor";

    char *t = "qhxepbshlrhoecdaodgpousbzfcqjxulatciapuftffahhlmxbufgjuxstfjvljybfxnenlacmjqoymvamphpxnolwijwcecgwbcjhgdybfffwoygikvoecdggplfohemfypxfsvdrseyhmvkoovxhdvoavsqqbrsqrkqhbtmgwaurgisloqjixfwfvwtszcxwktkwesaxsmhsvlitegrlzkvfqoiiwxbzskzoewbkxtphapavbyvhzvgrrfriddnsrftfowhdanvhjvurhljmpxvpddxmzfgwwpkjrfgqptrmumoemhfpojnxzwlrxkcafvbhlwrapubhveattfifsmiounhqusvhywnxhwrgamgnesxmzliyzisqrwvkiyderyotxhwspqrrkeczjysfujvovsfcfouykcqyjoobfdgnlswfzjmyucaxuaslzwfnetekymrwbvponiaojdqnbmboldvvitamntwnyaeppjaohwkrisrlrgwcjqqgxeqerjrbapfzurcwxhcwzugcgnirkkrxdthtbmdqgvqxilllrsbwjhwqszrjtzyetwubdrlyakzxcveufvhqugyawvkivwonvmrgnchkzdysngqdibhkyboyftxcvvjoggecjsajbuqkjjxfvynrjsnvtfvgpgveycxidhhfauvjovmnbqgoxsafknluyimkczykwdgvqwlvvgdmufxdypwnajkncoynqticfetcdafvtqszuwfmrdggifokwmkgzuxnhncmnsstffqpqbplypapctctfhqpihavligbrutxmmygiyaklqtakdidvnvrjfteazeqmbgklrgrorudayokxptswwkcircwuhcavhdparjfkjypkyxhbgwxbkvpvrtzjaetahmxevmkhdfyidhrdeejapfbafwmdqjqszwnwzgclitdhlnkaiyldwkwwzvhyorgbysyjbxsspnjdewjxbhpsvj";

//    char *s = "abcd";
//    char *t = "sabcd";
    char r = findTheDifference(s, t);
    printf(" %c ", r);
}

#pragma mark - 412. Fizz Buzz

char** fizzBuzz(int n, int* returnSize) {
    int i = 1;
    *returnSize = n;
    char **result = (char **)malloc(sizeof(char *) * n);
    while (i < n+1) {
        char *buffer = (char *)malloc(sizeof(char) * 10);
        if (i%5==0 && i%3==0) {
            sprintf(buffer, "%s", "FizzBuzz");
        } else if (i%3==0) {
            sprintf(buffer, "%s", "Fizz");
        } else if (i%5==0) {
            sprintf(buffer, "%s", "Buzz");
        } else {
            sprintf(buffer, "%d", i);
        }
        result[i-1] = buffer;
        i++;
    }
    return result;
}

void run412() {
    int size = 30;
    char **result = fizzBuzz(size, &size);
    printf("\n");
    for (int i = 0; i < size; i++) {
        char *value = result[i];
        printf("%s \n", value);
    }
}

#pragma mark - 225. Implement Stack using Queues
//https://leetcode.com/problems/implement-stack-using-queues/

typedef struct {
    int size;
    int currentSize;
    int *content;
} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    stack = (Stack *)malloc(sizeof(Stack));
    stack->size = maxSize;
    stack->currentSize = 0;
    stack->content = (int *)calloc(maxSize, sizeof(int));
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    if (stack->size == stack->currentSize) {
        return;
    }
    (stack->content)[stack->currentSize] = element;
    stack->currentSize++;
}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    if (!stack->currentSize) {
        return;
    }
    stack->currentSize--;
}

/* Get the top element */
int stackTop(Stack *stack) {
    return (stack->content)[stack->currentSize];
}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    return stack->currentSize;
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    free(stack->content);
    free(stack);
}

void run225() {
    Stack *s = NULL;
    stackCreate((Stack*)&s, 10);
    stackPush((Stack*)&s, 44);
    stackPush((Stack*)&s, 45);
    stackPop((Stack*)&s);
    printf("\n%d", stackTop((Stack*)&s));
    stackDestroy((Stack*)&s);
}

#pragma mark - 205. Isomorphic Strings
//https://leetcode.com/problems/isomorphic-strings/

bool isIsomorphic(char* s, char* t) {
    char *mapA = calloc(256, sizeof(char));
    char *mapB = calloc(256, sizeof(char));
    size_t length = strlen(s);
    bool isSame = true;
    for (int i = 0; i< length; i++) {
        char a = s[i];
        char b = t[i];
        if (mapA[a]==0) {
            mapA[a] = b;
        }
        if (mapB[b]==0) {
            mapB[b] = a;
        }
        if (mapA[a] != b || mapB[b] != a) {
            isSame = false;
            break;
        }
    }
    return isSame;
}

void run205() {
    char *s = "ab";
    char *t = "aa";
    isIsomorphic(s, t);
}

#pragma mark - 9. Palindrome Number
//https://leetcode.com/problems/palindrome-number/

bool isPalindrome9(int x) {
    if (x < 0) {
        return false;
    }
    int t = x;
    int r = 0;
    while(t){
        r *= 10;
        r+= t %10;
        t /=10;
    }
    return r==x;
}

void run9() {
    isPalindrome9(-231);
    isPalindrome9(110);
}

#pragma mark - 107. Binary Tree Level Order Traversal II
//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

struct CountNode {
    int level;
    int count;
    struct CountNode *next;
};


int countTree(struct TreeNode* root, struct CountNode* countNode, int level) {
    if(root == NULL) {
        return 0;
    }
    countNode->count += 1;

    struct CountNode *nextCountNode = NULL;
    if (root->left || root->right) {
        if (countNode->next != NULL) {
            nextCountNode = countNode->next;
        } else {
            nextCountNode = (void *)malloc(sizeof(struct CountNode));
            nextCountNode ->level = level + 1;
            nextCountNode ->count = 0;
            nextCountNode ->next = 0;
            countNode->next = nextCountNode;
        }
    }
    int left = countTree(root->left, nextCountNode, level+1);
    int right = countTree(root->right, nextCountNode, level+1);
    return left > right ? left+1 :right+1;
}

void travelTree(struct TreeNode *root, int level, int **result, int *records) {
    if (root == NULL) {
        return ;
    }
    int *array = result[level];
    int index = records[level];
    array[index] = root->val;
    index++;
    records[level] = index;
    travelTree(root->left, level+1, result, records);
    travelTree(root->right, level+1, result, records);
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == 0) {
        *columnSizes = 0;
        *returnSize = 0;
        return NULL;
    }
    struct CountNode *count = (struct CountNode *)malloc(sizeof(struct CountNode));
    struct CountNode *temp = count;
    count ->count = 0;
    count ->level = 0;
    count ->next = NULL;
    int depth = countTree(root, count, 0);
    *returnSize = depth;

    int *records = (int *)malloc(sizeof(int) * depth);

    *columnSizes = (int *)malloc(sizeof(int) * depth);
    int **result = (int **)malloc(sizeof(int *) * depth);
    int index = 0;
    while (temp) {
        (*columnSizes)[index] = temp->count;
        int *array = (int *)calloc(temp->count, sizeof(int));
        result[index] = array;
        records[index]= 0;
        index ++;
        temp = temp->next;
    }
    travelTree(root, 0, result, records);
    for (int i = 0; i < depth /2 ; i++) {
        int value = (*columnSizes)[i];
        (*columnSizes)[i] = (*columnSizes)[depth-i-1];
        (*columnSizes)[depth-i-1] = value;

        int *array = result[i];
        result[i] = result[depth-i-1];
        result[depth-i-1] = array;
    }
    return result;
}

void run107() {
    char *input = "[-2,0,-1,null,3,0,null,6,null,5,-5]";
    //    char *input = "[1]";
    struct TreeNode* root = createTreeByString(input);
    int returnSize = 0;
    int *columnSizes;
    int **result = levelOrderBottom(root, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("Line: %d\n", i);
        int *array = result[i];
        for (int j = 0; j < columnSizes[i]; j++) {
            printf(" %d", array[j]);
        }
        printf("\n");
    }

}

#pragma mark - 102. Binary Tree Level Order Traversal
//https://leetcode.com/problems/binary-tree-level-order-traversal/

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



int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == 0) {
        *columnSizes = 0;
        *returnSize = 0;
        return NULL;
    }
    struct CountNode *count = (struct CountNode *)malloc(sizeof(struct CountNode));
    struct CountNode *temp = count;
    count ->count = 0;
    count ->level = 0;
    count ->next = NULL;
    int depth = countTree(root, count, 0);
    *returnSize = depth;

    int *records = (int *)malloc(sizeof(int) * depth);

    *columnSizes = (int *)malloc(sizeof(int) * depth);
    int **result = (int **)malloc(sizeof(int *) * depth);
    int index = 0;
    while (temp) {
        (*columnSizes)[index] = temp->count;
        int *array = (int *)calloc(temp->count, sizeof(int));
        result[index] = array;
        records[index]= 0;
        index ++;
        temp = temp->next;
    }
    travelTree(root, 0, result, records);
    return result;
}

void run102() {
    char *input = "[-2,0,-1,null,3,0,null,6,null,5,-5]";
    //    char *input = "[1]";
    struct TreeNode* root = createTreeByString(input);
    int returnSize = 0;
    int *columnSizes;
    int **result = levelOrder(root, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("Line: %d\n", i);
        int *array = result[i];
        for (int j = 0; j < columnSizes[i]; j++) {
            printf(" %d", array[j]);
        }
        printf("\n");
    }
}

#pragma mark - 14. Longest Common Prefix
//https://leetcode.com/problems/longest-common-prefix/

char* longestCommonPrefix(char** strs, int strsSize) {
    size_t maxSize = 0;
    size_t minSize = INT_MAX;
    for (int i = 0 ; i < strsSize; i++) {
        size_t size = strlen(strs[i]);
        if (size > maxSize) {
            maxSize = size;
        }
        if (size < minSize) {
            minSize = size;
        }
    }
    if (maxSize == 0 ) {
        return "";
    }
    char *result = malloc(maxSize+1);

    char temp;
    bool end = false;
    maxSize = 0;
    for (int index = 0 ; index < minSize; index++) {
        temp = strs[0][index];
        for (int j = 1 ; j < strsSize; j++) {
            if (temp != strs[j][index]) {
                end = true;
                break;
            }
        }
        if (end) {
            break;
        } else {
            maxSize++;
            result[index] = temp;
        }
    }
    result[maxSize] = '\0';
    return result;
}

void run14() {
    char * input[2] = {"cba",""};
    char *result = longestCommonPrefix(input, 2);

    printf("result %s",result);
}


#pragma mark - 119. Pascal's Triangle II
//https://leetcode.com/problems/pascals-triangle-ii/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int **result = (int **)malloc(sizeof(int *) * (*returnSize));
    int *sizes = (int *)malloc(sizeof(int *) * (*returnSize));
    for (int i = 0 ; i < (*returnSize); i++) {
        int *array = (int *)malloc(sizeof(int) * (*returnSize));
        for (int j = 0 ; j < i + 1; j ++ ) {
            if (j == 0 || j == i) {
                array[j] = 1;
            } else {
                array[j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        result[i] = array;
        sizes[i] = i + 1;
    }
    return result[rowIndex];
}

void run119() {
    printf("run119 \n");
    for (int i = 0 ; i < 10; i++) {
        int size;
        int *row = getRow(i, &size);
        for (int j = 0; j < size; j++) {
            printf("%d ", row[j]);
        }
        printf("\n");
    }
}

#pragma mark - 118. Pascal's Triangle
//https://leetcode.com/problems/pascals-triangle/submissions/

int** generate(int numRows, int** columnSizes, int* returnSize) {
    int **result = (int **)malloc(sizeof(int *) * numRows);
    int *sizes = (int *)malloc(sizeof(int *) * numRows);
    *returnSize = numRows;
    for (int i = 0 ; i < numRows; i++) {
        int *array = (int *)malloc(sizeof(int) * (numRows + 1));
        for (int j = 0 ; j < i + 1; j ++ ) {
            if (j == 0 || j == i) {
                array[j] = 1;
            } else {
                array[j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        result[i] = array;
        sizes[i] = i + 1;
    }
    *columnSizes = sizes;
    return result;
}


#pragma mark - 299. Bulls and Cows
//https://leetcode.com/problems/bulls-and-cows/

char* getHint(char* secret, char* guess) {

    int A = 0;
    int length = (int)strlen(secret);
    int groupA[10] = {0};
    int groupB[10] = {0};
    while (length) {
        int index = length-1;
        int s = secret[index]-'0';
        int g = guess[index]-'0';
        if (s == g) {
            A++;
        } else {
            groupA[s]++;
            groupB[g]++;
        }
        length--;
    }
    int B = 0;
    for (int i = 0 ; i < 10; i++) {
        int times = groupA[i]>groupB[i]?groupB[i]:groupA[i];
        B+=times;
    }
    char *result = malloc(10);
    sprintf(result, "%dA%dB", A, B);

    return result;
}

void run299() {
    printf("run299\n");
    char *result =  getHint("1807", "7810");
    printf("result %s\n", result);
}

#pragma mark - 67. Add Binary
//https://leetcode.com/problems/add-binary/

//int charToValue(char *a){
//    int length = (int)strlen(a);
//    int result = 0;
//    for (int i = 0 ; i < length; i++) {
//        char t = a[i];
//        result = (result << 1) + (t - '0');
//    }
//    return result;
//}
//
//char *valueToString(const int value) {
//    if (value == 0) {
//        return "0";
//    }
//    int temp = value;
//    int binarys[32] = {0};
//    int length = 0;
//    while (temp) {
//        binarys[length] = temp % 2;
//        length ++;
//        temp = temp / 2;
//    }
//    char *result = (char *)malloc(sizeof(char)*length+1);
//    for (int i = 0 ; i < length; i++) {
//        int value = binarys[i];
//        if (value) {
//            result[length-i-1] = '1';
//        } else {
//            result[length-i-1] = '0';
//        }
//    }
//    result[length] = '\0';
//    return result;
//}

char* addBinary(char* a, char* b) {

    int lengthA = (int)strlen(a);
    int lengthB = (int)strlen(b);
    int maxLength = lengthA > lengthB ? lengthA : lengthB;

    int step = 0;
    char *result = malloc(maxLength+2);
    result[maxLength + 1] = '\0';

    for (int i = 0; i < maxLength ; i ++) {
        int vA = 0;
        int vB = 0;
        if (lengthA) {
            vA = a[--lengthA] - '0';
        }
        if (lengthB) {
            vB = b[--lengthB] - '0';
        }
        int vC = vA + vB + step;
        if (vC >= 2) {
            step = 1;
        } else {
            step = 0;
        }
        vC = vC % 2;
        int location = maxLength - i;
        result[location] = vC + '0';
    }

    if (step) {
        result[0] = 1 + '0';
    } else {
        result ++;
    }
    return result;
}

void run67(){
    printf("run67 \n");
//    char *result = addBinary("10", "1");
//    printf("%s",result);

//    char *result = addBinary("0", "0");
//    printf("%s \n",result);

    char *result = addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101", "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011");
//    110111101100010011000101110110100000011101000101011001000011011000001100011110011010010011000000000
    printf("%s \n",result);
}

#pragma mark - 204. Count Primes
//https://leetcode.com/problems/count-primes/

bool isPrimes(int n) {
    int max = sqrt(n);
    bool isPrime = true;
//    if (n > 10) {
//        int v = n %10;
//        switch (v) {
//            case 1:
//            case 3:
//            case 7:
//            case 9:
//                break;
//
//            default:
//                return false;
//                break;
//        }
//    }
    if (n > 10 && n % 5 == 0) {
        return false;
    }
    for (int i = 2; i <=max; i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}



int countPrimes(int n) {
    if (n <= 2) {
        return 0;
    }
    if (n == 3) {
        return 1;
    }
    int sum = 1;    //Time Limit Exceeded
    for (int i = 3; i < n; i+=2) {
        if (isPrimes(i)) {
            sum++;
        }
    }
    return sum;
}

void run204() {
    printf("run204 \n");
//    int result = countPrimes(3);
//    printf("result %d \n", result);
    int result = countPrimes(150000);
    printf("result %d \n", result);

}

#pragma mark - 19. Remove Nth Node From End of List
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL || n == 0) {
        return head;
    }

    struct ListNode *tailNode = head;
    int index = 0;
    while (tailNode) {
        index ++;
        if (n == index) {
            break;
        }
        tailNode = tailNode->next;
    }
    if (tailNode == NULL) {
        return head->next;
    }


    struct ListNode *pre = head;
    struct ListNode *target = head;
    while (tailNode->next) {
        target = target->next;
        tailNode = tailNode->next;
        if (pre ->next == target) {
            continue;
        } else {
            pre = pre ->next;
        }
    }
    if (pre == target) {
        return pre->next;
    }

    if (target) {
        pre->next = target->next;
    } else {
        pre->next = NULL;
    }

    return head;
}

void run19() {
    printf("19.\n");
    int size = 1;
//    int *inputArray = randomArray(size, 100);
    int inputArray[] = {1,2,3};
    struct ListNode *list =  createLinkList(inputArray, size);
    struct ListNode* removeNode = removeNthFromEnd(list, 0);

    printLinkList(removeNode);

}


#pragma mark - 8. String to Integer
//https://leetcode.com/problems/string-to-integer-atoi/

//Very hard.
int myAtoi(char* str) {
    int n=0; bool negtive=false;
    int tenth=INT_MAX/10;

    while (*str==' ') str++;
    if (*str=='+') str++;
    else if (*str=='-') {negtive=true; str++;}

    while (*str) {
        if (*str<'0' || *str>'9') break;
        if (n<=tenth) {
            n=n*10+(int)(*str-'0');
            if (n>=0) {str++; continue;}//continue if not oveflowed
        }
        //if overflowed
        if (negtive) return INT_MIN;
        return INT_MAX;
    }

    if (negtive) n=-n;
    return n;


}

void run8() {
    printf("8. %d \n", myAtoi("  -0012a42"));
}

#pragma mark - 66. Plus One
//https://leetcode.com/problems/plus-one/

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int steps = 1;
    for (int i = digitsSize-1; i >= 0 ; i--) {
        digits[i] = digits[i] + steps;
        steps = digits[i] / 10;
        digits[i] = digits[i] % 10;
    }

    if (steps) {
        int *digits2 = (int *)malloc(sizeof(int) * (digitsSize+1));
        digits2[0] = steps;
        for (int i = 0; i < digitsSize; i++) {
            digits2[i+1] = digits[i];
        }
        *returnSize = digitsSize + 1;
        return digits2;
    }
    *returnSize = digitsSize;
    return digits;
}

void run66() {
    int returnSize = 0;
    int digits[] = {1000};
    int *result = plusOne(digits, 1, &returnSize);
    for (int i =0 ; i < returnSize; i++) {
        printf(" %d", result[i]);
    }

}

#pragma mark - 189. Rotate Array
//https://leetcode.com/problems/rotate-array/

void reverse(int *nums, int size) {
    if (size < 2) {
        return;
    }
    for (int i = 0 ; i < size / 2 ; i++) {
        int temp = nums[i];
        nums[i] = nums[size - 1 - i];
        nums[size - 1 - i] = temp;
    }
}

void rotate(int* nums, int numsSize, int k) {

    k = k % numsSize;   //what dose the k meaning?
    reverse(nums, numsSize);
    reverse(nums, k);
    reverse(nums + k, numsSize - k);
}

void run187(){
    //    int input[] = {1,2,3};
    //    rotate(input, 3, 4);
    int input[] = {1,2,3,4,5,6};
    rotate(input, 6, 11);
    for (int i = 0 ; i < 7; i++) {
        printf("187. %d \n", input[i]);
    }
}

#pragma mark - 125. Valid Palindrome
//https://leetcode.com/problems/valid-palindrome/


bool isAlphabet(char alphabet) {
    if ((alphabet >='a' && alphabet <='z') || (alphabet >='A' && alphabet <='Z') || (alphabet >='0' && alphabet <='9')) {
        return true;
    }
    return false;
}

bool isSameAlphabet(char input1, char input2) {
    char check1, check2;
    if (input1 >= 'a') {
        check1 = input1 - 'a' + 'A';
    } else {
        check1 = input1;
    }

    if (input2 >= 'a') {
        check2 = input2 - 'a' + 'A';
    } else {
        check2 = input2;
    }

    if (check1 == check2) {
        return true;
    }
    return false;
}

bool isPalindrome(char* s) {

    int length = (int)strlen(s);
    int left = 0;
    int right = length-1;
    while (left <= right) {
        char leftA = s[left];
        if (!isAlphabet(leftA)) {
            left++;
            continue;
        }
        char rightA = s[right];
        if (!isAlphabet(rightA)) {
            right--;
            continue;
        }

        if (isSameAlphabet(leftA, rightA)) {
            left++;
            right--;
        } else {
            return false;
        }

    }
    return true;
}

void run125(){
    //    bool result = isPalindrome("A man, a plan, a canal: Panama");
    //    printf("125. result %d", result);
    bool result = isPalindrome("0P");
    printf("125. result %d", result);
}

#pragma mark - 345. Reverse Vowels of a String
//https://leetcode.com/problems/reverse-vowels-of-a-string/



int isVowels(char letter) {
    switch (letter) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'u':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

char* reverseVowels(char* s) {

    size_t length = strlen(s);
    if (length == 0) {
        return s;
    }
    int left = 0;
    int right = (int)length - 1;

    //size_t -- 不会出现负数 a. 会出现（right = 0-1） > left的情况
    while (left <= right) {
        char leftletter = s[left];
        if (!isVowels(leftletter)) {
            left++;
            continue;
        }
        char rightletter = s[right];
        if (!isVowels(rightletter)) {
            right--;
            continue;
        }
        s[left] = rightletter;
        s[right] = leftletter;
        right--;
        left++;
    }
    return s;
}

void run345(){
    char str[ ]="a.";
    char* ss = reverseVowels(str);
    printf("reverseVowels: %s\n", ss);

}

#pragma mark - 350. Intersection of Two Arrays II
//https://leetcode.com/problems/intersection-of-two-arrays-ii/

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    qsort(nums1, nums1Size, sizeof(nums1[0]), cmp);
    qsort(nums2, nums2Size, sizeof(nums2[0]), cmp);

    int minSize = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *result =  (int *)malloc(sizeof(int)*minSize);
    int resultSize = 0;

    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size) {
        int num1 = nums1[i];
        int num2 = nums2[j];
        if (num1 == num2) {
            result[resultSize] = num2;
            i++;
            j++;
            resultSize ++;
        }else if (num1 > num2) {
            j ++ ;
        } else {
            i ++ ;
        }
    }
    *returnSize = resultSize;

    return result;
}

void run350(){

    int input1[10] = {123,3,14,5,1234,156,3,7,1,19};
    int input2[6] = {4,11,2,46,1,1234};

    int size = 0;
    int *result = intersect(input1, 10, input2, 6, &size);

    for (int i = 0 ; i < size; i++) {
        printf("%d\n", result[i]);
    }
}

#pragma mark - 349. Intersection of Two Arrays
//https://leetcode.com/problems/intersection-of-two-arrays/

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int min = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *result = (int *)malloc(sizeof(int) * min);
    int size = 0;
    for (int i = 0; i < nums1Size; i++) {
        int check = nums1[i];
        int exist = 0;
        for (int j = 0; j < size; j++) {
            if (result[j] == check) {
                exist = 1;
                break;
            }
        }
        if (exist) {
            continue;
        }
        for (int j = 0; j < nums2Size; j++) {
            if (nums2[j] == check) {
                exist = 1;
                break;
            }
        }
        if (exist) {
            result[size] = check;
            size++;
        }
    }
    *returnSize = size;
    return result;
}

void run349(){
    int input1[] = {1,2,4,3,4,1};
    int input2[] = {2,1,2,4};
    int size1 = sizeof(input1)/sizeof(int);
    int size2 = sizeof(input2)/sizeof(int);
    int returnSize = 0;
    int *result = intersection(input1, size1, input2, size2, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d \n", result[i]);
    }
}

#pragma mark - 371 Sum of Two Integers

int getSum(int a, int b) {
    int result = 0;
    int carry = 0;

    while (b) {
        result = a ^ b;
        carry = a & b;
        a = result;
        b = carry<<1;
    }
    return result;
}

void run371() {
    printf("371. result %d \n", getSum(3, 31));
}

#pragma mark - 344. Reverse String
//https://leetcode.com/problems/reverse-string/
char* reverseString(char* s) {
    long length = strlen(s);
    char *resut;
    resut = (char *)malloc((length + 1) * sizeof(char));    //key point is length + 1.. , and then result[length] = '\0';
    for (long i = 0; i<length; i++) {
        resut[i] = s[length-i-1];
    }
    resut[length] = '\0';
    return resut;
}


void run344() {

    char *input = "race car";
    char *result = reverseString(input);
    printf("344. result %s \n", result);
}


#pragma mark - 121. Best Time to Buy and Sell Stock
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(int* prices, int pricesSize) {

//Version 1.0 Time Limit Exceeded
    int result = 0;
//    for (int i = 0; i < pricesSize - 1; i++) {
//        for (int j = i+1; j < pricesSize; j++) {
//            int temp  = prices[j] - prices[i];
//            if (temp > result) {
//                result = temp;
//            }
//        }
//    }

//Version 2.0
    int minValue = INT_MAX;
    for (int i = 0; i < pricesSize; i++) {
        if (minValue > prices[i]) {
            minValue = prices[i];
        }
        int temp = prices[i] - minValue;
        if (temp > result) {
            result = temp;
        }
    }
    return result;
}

void run121() {
//Input: [7, 1, 5, 3, 6, 4]
//Output: 5
    int input[6] = {7,1,5,3,6,4};
    int size = sizeof(input)/sizeof(int);
    int result = maxProfit(input, size);
    printf("121. result %d \n", result);
}


#pragma mark - Go

void runEasyPart() {
//    run371();
//    run349();
//    run350();
//    run121();
//    run342();
//    run345();
//    run350();
//    run125();
//    run187();
//    run66();
//    run8();
//    run19();
//    run204();
//    run67();
//    run299();
//    run119();
//    run14();
//    run107();
//    run225();
//    run205();
//    run412();
//    run389();
//    run404();
//    run383();
//    run387();
//    run409();
//    run401();
//    run415();
//    run257();
//    run441();
//    run405();
//    run438();
//    run461();
//    run38();
//    run414();
//    run400();
//    run453();
//    run437();
//    run461();
//    run448();
//    run463();
}
