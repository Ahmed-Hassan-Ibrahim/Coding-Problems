/*=======================================================================================================
=========================================================================================================
You have a long flowerbed in which some of the plots are planted, and some are not. 
However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, 
return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
=======================================================================================================
=======================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_vowel(char s)
{
    if(s == 'I' || s == 'O' || s == 'U' || s == 'A' || s == 'E' || 
       s == 'i' || s == 'o' || s == 'u' || s == 'a' || s == 'e')
        return true;
    else
        return false;
}

char* reverseVowels(char* s) {
    int size = (int)strlen(s);
    char* vowel = malloc((size+1)*sizeof(char));
    int i, j = 0;

    for(i = 0; i < size; i++)
    {
        if(is_vowel(s[i]))
            vowel[j++] = s[i];
    }

    vowel[j] = '\0';

    for(i = 0; i < size; i++)
    {
        if(is_vowel(s[i]))
            s[i] = vowel[--j];
    }

    free(vowel);
    return s;
}

int main()
{
    char str[6] = "H";
    reverseVowels(str);
}