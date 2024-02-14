/*=======================================================================================================
=========================================================================================================
There are n kids with candies. 
You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, 
and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, 
they will have the greatest number of candies among all the kids, or false otherwise.
=======================================================================================================
=======================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int largest_element(int *arr, int size)
{
    int i, result = 0;

    for(i = 0; i < size; i++)
    {
        if (result < arr[i])
            result = arr[i];
    }

    return result;
}

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int i, max_candy;
    bool* result = malloc((candiesSize+1)*sizeof(bool));
    *returnSize = candiesSize;

    max_candy = largest_element(candies, candiesSize);

    for(i = 0; i < candiesSize; i++)
    {
        if(candies[i] + extraCandies >= max_candy)
            result[i] = true;
        else
            result[i] = false;
    }
    
    return result;
}