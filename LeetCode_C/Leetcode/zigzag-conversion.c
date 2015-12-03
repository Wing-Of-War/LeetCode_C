//
//  zigzag-conversion.c
//  LeetCode_C
//
//  Created by 张珏 on 15/12/3.
//  Copyright © 2015年 JUE DUKE. All rights reserved.
//

#include "zigzag-conversion.h"
#include "string.h"
#include "stdlib.h"


void testZigzag(void) {
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