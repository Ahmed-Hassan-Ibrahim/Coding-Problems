/*=======================================================================================================
=========================================================================================================
Given an integer array nums, return an array answer such that answer[i] is equal to the product 
of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
=======================================================================================================
=======================================================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);

        // Check product left side to the element
        int left_product = 1;
        for (int i = 0; i < size; i++) {
            result[i] = left_product;
            left_product *= nums[i];
        }

        // Check product right side of element after calculating left side
        int right_product = 1;
        for (int i = size - 1; i >= 0; i--) {
            result[i] *= right_product;
            right_product *= nums[i];
        }

        return result;
    }
};
