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

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i;

    if(flowerbedSize == 1)
    {
        if(flowerbed[0] && n)
            return false;
        else
            return true;
    }
    for(i = 0; n > 0 && i < flowerbedSize; i++)
    {
        if(i == 0)
        {
            if(flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                --n;
            }
        }

        else if(i == (flowerbedSize - 1))
        {
            if(flowerbed[i] == 0 && flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                --n;
            }
        }

        else
        {
            if(flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                --n;
            }
        }
    }

    if(n)
        return false;
    else 
        return true;
}

