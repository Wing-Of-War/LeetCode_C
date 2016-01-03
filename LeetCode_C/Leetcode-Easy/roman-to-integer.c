//
//  roman-to-integer.c
//  LeetCode_C
//
//  Created by JUE DUKE on 1/3/16.
//  Copyright © 2016 JUE DUKE. All rights reserved.
//

#include "roman-to-integer.h"



void testRomanToInt(void) {
//    char *s = "MCD";
//    char *s = "LXXX";
//    char *s = "MDCCCLXXXIV";
    char *s = "CMLII";
    int value = romanToInt(s);
    printf("Roman Value: %d", value);
    
}


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