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
#include "PublicUtilize.h"


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
    double result =  log(n)/log(3.0);
    double rest = result -  round(result) ;
    if (fabs(rest) < 1e-13) {
        return true;
    }
    return false;
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


int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int*)b);  //I can't figure out.
}

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
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
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
    for (int index; index < 26; index++) {
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
    run441();
}
