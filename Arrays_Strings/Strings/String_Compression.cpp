/*=======================================================================================================
=========================================================================================================
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

- If the group's length is 1, append the character to s.
- Otherwise, append the character followed by the group's length.

The compressed string s should not be returned separately, but instead, be stored in the input character array chars. 
Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
=======================================================================================================
=======================================================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int j, size = chars.size(), counter1 = 1, counter2 = 0, counter3 = 0, counter4 = 0;

        // Array is single element
        if(size == 1)
            return 1;

        for(int i = 0; i < size; i++)
        {
            j = i + 1;
            while(j < size && chars[i] == chars[j])
            {
                counter1++;
                j++;
                i++;

                // Number of repeated letters greater than 10
                if(counter1 == 10)
                {
                    counter2++;
                    counter1 = 0;
                } 
                // Number of repeated letters greater than 100
                if(counter2 == 10)
                {
                    counter3++;
                    counter2 = 0;
                }
                // Number of repeated letters greater than 1000
                if(counter3 == 10)
                {
                    counter4++;
                    counter3 = 0;
                } 
            }
            //Push character once
            chars.push_back(chars[i]);

            // Push How many times character is repeated 
            if(counter1 > 1 || counter2 || counter3 || counter4)
            {
                if(counter2 || counter3 || counter4)
                {
                    if(counter3 || counter4)
                    {
                        if(counter4)
                            chars.push_back(counter4 + 48);
                        chars.push_back(counter3 + 48);
                    }
                    chars.push_back(counter2 + 48);
                }       
                chars.push_back(counter1 + 48);
            }  

            // Reset for new letter
            counter1 = 1;
            counter2 = 0;
            counter3 = 0;
            counter4 = 0;
        }

        // Erase the character vector except the compression part
        chars.erase(chars.begin(), chars.begin() + size);

        return chars.size();
    }
};
