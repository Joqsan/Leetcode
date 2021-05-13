#include <vector>
#include <numeric>
#include <iostream>

using namespace std;


/*
 
 Find the contribution of each element to the final sum:
 
 - Consider the element array A[i].
 - There are i+1 arrays ending at A[i]:
    - the array beginning at A[0]
    - the array beginning at A[1]
    - ...
    - the array beginning at A[i].
 
 - There are n-1-i+1 arrays starting at A[i]:
    - the array ending at A[i].
    - the array ending at A[i+1].
    - ...
    - the array ending at A[n-1].

 - ==> The element A[i] will appear in k = (i+1)*(n-i) subarrays.
 - (k + 1) / 2 will be of odd length (this is what we need).
 - k / 2 of even length.
 

 
 Complexity:
 - Time: O(N).
 - Space: O(1).
 
 */

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int>& arr)
    {
        
        int total = 0, N = arr.size();
        for (int i = 0; i != N; ++i)
            total += ((i + 1) * (N - i) + 1) / 2 * arr[i];
        
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


