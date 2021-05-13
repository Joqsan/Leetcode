#include <vector>

using namespace std;


/*
 
 Count how many odd numbers are in the array.
 If odd, the product is -ve.
 If even, it's +ve.
 */

class Solution
{
public:
    int arraySign(vector<int>& nums)
    {
        int odd_counter = 0;
        
        for (auto n : nums)
        {
            if (n == 0)
                return 0;
            else if (n < 0)
                ++odd_counter;
        }
        
        if (odd_counter % 2 == 0)
            return 1;
        else
            return -1;
    }
};
