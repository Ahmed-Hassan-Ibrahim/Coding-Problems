/*=======================================================================================================
=========================================================================================================
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.
=======================================================================================================
=======================================================================================================*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string word = "", result = "";
        int j = 0, size = s.size();

        // Handle spaces at the beginning
        while(s[j] == ' ')
            j++;
        
        for(int i = j; i <size; i++)
        {
            // Store word 
            if(s[i] != ' ')
            {
                word += s[i];
            }

            else
            {
                // Result already contain a word --> add new word to front
                if(result != "")
                    result = word + " " + result;
                // First word to add
                else
                    result = word;

                // Prepare for new word
                word = "";

                // Skip spaces in the middle of string
                i++;
                while(s[i] == ' ')
                    i++;
                i--;
            }
        }

        // Handle last word in string with no space at the end
        if(word != "" && result != "")
            result = word + " " + result;
        else if(word != "")
            result = word;
        
        return result;
    }
};
