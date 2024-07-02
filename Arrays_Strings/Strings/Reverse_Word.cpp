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
