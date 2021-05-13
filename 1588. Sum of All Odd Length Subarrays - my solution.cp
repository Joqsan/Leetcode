#include <vector>
#include <numeric>
#include <iostream>

using namespace std;


/*
 
 Sliding window.
 
 Complexity:
 - Time: O()
 
 */
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int>& arr)
    {
        int N = arr.size();
        
        int total = 0;
        for (int width = 1, k=1; width <= N; width = 2*k + 1, ++k)
            for (int i = 0; i <= N-width; ++i)
            {
                int start = i;
                int end = i + width;
                
                total += accumulate(arr.begin() + start, arr.begin() + end, 0);
            }
        
        return total;
    }
};

int main(void)
{
    vector<int> nums{1,4,2,5,3};
    
    Solution sol = Solution();
    
    cout << sol.sumOddLengthSubarrays(nums) << endl;
    
    return 0;
}


