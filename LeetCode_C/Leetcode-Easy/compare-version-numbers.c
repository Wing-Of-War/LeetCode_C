//
//  compare-version-numbers.c
//  LeetCode_C
//
//  Created by JUE DUKE on 15/12/20.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "compare-version-numbers.h"

#include "string.h"



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




void testCompareVersion(void) {
    
//    int result = compareVersion("0.1.1", "0.2.1");
//    printf("result %d", result);

//    int result = compareVersion("1", "1.1");
//    printf("result %d", result);

//    int result = compareVersion("01", "1");
//    printf("result %d", result);

    int result = compareVersion("1.0", "1");
    printf("result %d", result);

}