/*=======================================================================================================
=========================================================================================================
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
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