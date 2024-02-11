/*=======================================================================================================
=========================================================================================================
You are given two strings word1 and word2. 
Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.
=======================================================================================================
=======================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mergeAlternately(char * word1, char * word2){
    int size_1 = (int)strlen(word1);
    int size_2 = (int)strlen(word2);
    int size = size_1 + size_2;
    char* result = malloc((size+1)*sizeof(char));
    int i = 0, j = 0, k = 0;
    
    while(j < size_1 || k < size_2)
    {
        if(j < size_1)
            result[i++] = word1[j++];

         if(k < size_2)
            result[i++] = word2[k++];           
    }

    result[i] = '\0';
    return result;
}