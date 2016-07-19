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

#pragma mark - 107. Binary Tree Level Order Traversal II
//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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

int maxDepth(struct TreeNode* root) {
    
    if(root == NULL) {
        return 0;
    }
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return left > right ? left+1 :right+1;
}

int power(int input, int times) {
    if (times == 0) {
        return 1;
    }
    int result = input;
    while (times > 0) {
        result *= input;
    }
    return result;
}

void saveTree(struct TreeNode *root,int **saveTable, int level) {
    if (root == NULL || saveTable == NULL) {
        return;
    }
    int *array = saveTable[level];
    if (array == NULL) {
        array = (int *)malloc(sizeof(int) * power(2, level));
        saveTable[level] = array;
    }
}



int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int depth = maxDepth(root);
    //    if (depth == 0) {
    //        *columnSizes = NULL;
    //        *returnSize = 0;
    //        return NULL;
    //    }
    //    *returnSize = depth;
    int *arraySize = (int *)malloc(sizeof(int) * depth);
    returnSize = arraySize;
    for (int i = 0; i < depth; i++) {
        printf(" %d", arraySize[i]);
    }
    int **result = (int **)malloc(sizeof(int *) * depth);
    //    saveTree(root, result, 0);
    
    
    
    return result;
}

void run107() {
//    Given binary tree [3,9,20,null,null,15,7],
    struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val = 1;
    node1->left = NULL;
    node1->right = NULL;
    node2->val = 2;
    node3->val = 3;
    node3->left = NULL;
    node3->right = NULL;
    node2->left = node1;
    node2->right = node3;
    
    
    int *columnSize;
    int returnSize;
    int **result;
    result = levelOrderBottom(node2, &columnSize, &returnSize);
    
    //    for (int i = 0 ; i < returnSize; i ++) {
    //        int col = columnSize[i];
    //        printf("level %d", i);
    //        for (int j = 0 ; j < col; j++) {
    //            printf("%d", result[i][j]);
    //        }
    //        printf("\n");
    //    }
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
//    run107();
}