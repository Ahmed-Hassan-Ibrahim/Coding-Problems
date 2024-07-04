/*=======================================================================================================
=========================================================================================================
Given an integer array nums, 
return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false.
=======================================================================================================
=======================================================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;  

        int left = INT_MAX, mid = INT_MAX;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < left)
                left = nums[i];
            if(nums[i] > left && nums[i] < mid)
                mid = nums[i];
            if(nums[i] > mid)
                return true;
        }
        return false;
    }
};

