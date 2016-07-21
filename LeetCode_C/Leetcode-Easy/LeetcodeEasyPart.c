//
//  LeetcodeEasyPart.c
//  LeetCode_C
//
//  Created by JUE DUKE on 7/5/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "LeetcodeEasyPart.h"
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "LinkedList.h"
#include "NumberArray.h"
#include "Tree.h"

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

struct CountNode {
    int level;
    int count;
    struct CountNode *next;
};

int countTree(struct TreeNode* root, struct CountNode* countNode, int level) {
    if(root == 0) {
        return 0;
    }
    struct CountNode *nextCountNode = 0;
    if (root->left || root->right) {
        if (countNode->next != 0) {
            nextCountNode = countNode->next;
        } else {
            nextCountNode = (void *)malloc(sizeof(struct CountNode));
            nextCountNode ->level = level + 1;
            nextCountNode ->count = 0;
            nextCountNode ->next = 0;
            countNode->next = nextCountNode;
        }
    }
    
    countNode->count += 1;


    int left = countTree(root->left, nextCountNode, level+1);
    int right = countTree(root->right, nextCountNode, level+1);
    return left > right ? left+1 :right+1;
}

void travelTree(struct TreeNode *root,int level, int **result) {
    if (root == 0) {
        return ;
    }
    int *array = result[level];
    int i = 0;
    while (array[i]) {
        i++;
    }
    array[i] = root->val;
    travelTree(root->left, level+1, result);
    travelTree(root->right, level+1, result);
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == 0) {
        *columnSizes = 0;
        *returnSize = 0;
        return 0;
    }
    struct CountNode *count = (struct CountNode *)malloc(sizeof(struct CountNode));
    struct CountNode *temp = count;
    count ->count = 0;
    count ->level = 0;
    count ->next = 0;
    int depth = countTree(root, count, 0);
    *returnSize = depth;
    
    *columnSizes = (int *)malloc(sizeof(int) * depth);
    int **result = (int **)malloc(sizeof(int *) * depth);
    for (int i = 0; i < depth; i++) {
        (*columnSizes)[i] = temp->count;
        int *array = (int *)calloc(temp->count, sizeof(int));
        temp = temp->next;
        result[i] = array;
//        printf(" %d", (*columnSizes)[i]);
    }
    
    travelTree(root, 0, result);
    return result;
}

void run107() {
//    int size = 10;
//    int *input = sortedArray(size);
    
    int input[] = {69,73,68,18,20,18,39,7,-3,13,-1,42,5,93,70,63,17,0,91,-4,30,0,-1,64,-4,16,49,48,78,51,43,92,45,0,53,9,36,80,-6,58,78,0,0,41,81,89,67,71,0,25,0,82,54,28,14,61,57,35,5,83,9,18,0,-9,-9,50,92,93,0,0,80,62,1,28,29,27,89,21,0,85,-9,0,56,56,-9,0,0,43,0,29,97,-7,0,35,25,90,67,53,18,61,7,23,81,37,19,26,2,0,19,0,0,77,37,-2,0,49,39,28,1,37,11,87,83,68,55,53,33,-2,22,7,52,0,14,0,18,50,97,-8,-7,0,21,59,72,27,0,64,0,0,47,0,0,38,46,0,0,99,0,0,48,13,85,78,7,64,43,59,71,11,37,12,37,50,2,0,0,89,87,0,78,97,0,31,86,37,96,34,38,6,36,0,0,99,63,0,12,0,82,0,81,70,19,0,81,32,0,0,0,0,79,10,0,91,48,-3,94,65,0,20,26,96,21,92,91,0,89,9,74,0,0,96,0,64,67,50,96,0,0,0,0,0,0,40,78,0,27,3,17,0,0,2,45,0,0,0,0,0,13,0,0,17,45,69,30,0,0,43,0,4,13,-6,66,6,0,16,48,55,98,69,57,0,5,9,65,-9,55,2,0,0,0,0,0,0,68,0,0,0,5,61,51,0,0,32,43,0,35,20,0,-7,38,30,1,80,0,0,42,86,42,0,0,0,0,47,0,0,0,62,29,-9,83,60,71,48,0,24,0,76,6,65,18,95,29,11,0,38,0,0,0,0,21,3,6,23,36,0,45,0,34,0,0,0,0,0,0,41,0,57,13,18,92,43,83,0,0,0,0,0,0,0,2,-4,97,0,93,0,62,0,0,48,18,71,92,53,89,0,0,0,95,0,16,0,0,0,83,87,5,0,0,3,-8,-4,65,0,0,0,22,0,31,0,0,0,63,0,0,62,0,57,12,85,45,23,55,0,0,0,81,83,23,0,3,0,83,0,-4,0,0,0,0,0,64,0,15,50,57,0,0,0,4,0,0,0,29,0,0,87,0,22,92,0,0,67,90,0,93,47,46,0,0,0,28,72,18,59,25,3,74,0,0,0,-5,28,-1,61,15,0,0,0,0,79,0,16,0,0,59,47,-7,98,31,50,0,0,0,0,19,0,93,0,22,0,0,-5,40,0,0,0,75,30,0,7,53,76,0,0,0,0,0,68,19,0,63,41,91,0,43,0,49,0,0,0,0,0,46,0,0,87,74,49,1,21,62,6,34,77,0,0,0,0,0,0,-9,61,0,0,0,7,0,45,0,0,63,0,0,7,0,0,16,86,0,0,63,0,61,72,0,13,0,24,91,0,0,59,0,0,48,14,77,0,0,0,0,92,0,0,0,0,0,0,84,0,0,76,82,63,84,84,94,0,0,0,0,0,47,40,0,0,0,0,75,20,0,0,0,-9,0,0,24,74,0,51,0,0,91,0,83,17,0,0,0,42,49,88,57,85,1,0,94,0,28,36,78,0,53,0,27,25,46,97,58,0,0,0,0,0,0,0,0,12,33,0,0,6,0,0,0,87,0,0,0,0,0,0,0,9,0,83,0,0,0,90,11,0,61,0,89,0,46,0,86,81,0,0,0,0,0,0,0,53,0,0,59,0,0,0,0,0,0,0,29,0,47,97,0,0,0,0,0,9,0,17,0,91,45,9,61,21,0,0,64,0,69,0,44,0,0,0,0,12,0,2,-8,88,0,0,0,0,0,-8,0,93,0,0,0,86,0,0,97,0,0,0,0,72,0,0,0,0,0,50,0,0,0,0,0,47,70,0,62,0,-3,-5,59,15,0,-3,37,0,0,0,0,20,-2,0,8,90,0,0,0,61,0,0,0,0,0,0,0,15,12,95,0,0,73,11,76,76,49,0,0,51,0,0,0,0,0,0,0,0,0,0,0,0,0,42,0,0,-9,0,0,0,0,0,0,0,0,80,0,0,70,31,78,98,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,57,0,0,0,0,-3,0,0,-7,0,31,42,0,0,0,0,62,17,7,0,0,63,0,0,0,0,83,51,0,76,77,0,0,40,0,0,95,0,27,55,61,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,95,0,93,19,0,37,0,73,0,0,0,0,0,75,0,0,0,0,0,22,0,0,0,0,0,-7,99,0,0,0,0,0,94,63,0,0,0,0,0,0,0,39,77,0,-2,15,0,69,33,9,0,0,0,0,0,0,0,0,0,42,0,0,0,69,35,0,36,0,11,0,0,0,52,0,0,0,0,0,0,0,51,50,0,0,0,0,0,0,30,0,0,0,0,0,63,0,0,0,0,0,0,56,28};
    
    
    int size = sizeof(input)/sizeof(int);
//    int input[] = {3,9,20,0,0,15,7};
    
    
//    [-2,0,-1,null,3,0,null,6,null,5,-5]

    struct TreeNode* root = creatTree(input, size);
//    outputArray(input, size);
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
    if (head == 0 || n == 0) {
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
    if (tailNode == 0) {
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
        pre->next = 0;
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

    showLinkList(removeNode);
    
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

void run342() {
    isPowerOfFour(16);
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
    run107();
}