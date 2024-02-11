/*=======================================================================================================
=========================================================================================================
For two strings s and t, we say "t divides s" if and only if s = t + ... + t 
(i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
=======================================================================================================
=======================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* gcdOfStrings(char* str1, char* str2) {
    int size_1 = (int)strlen(str1);
    int size_2 = (int)strlen(str2);
    
    if(size_1 < size_2)
        return gcdOfStrings(str2, str1);
    else if(strncmp(str1, str2, size_2) != 0)
        return "";
    else if(size_2 == 0)
        return str1;
    else
    {
        memmove(str1, str1 + size_2, size_1 - size_2);
        str1[size_1 - size_2] = '\0';
        return gcdOfStrings(str1, str2);
    }
}