#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 
    |   |   |   |   |   |   |   |   |
        odd,i           even,j
 
 i: pointer to the first odd number to swap
 j: pointer to first even number found
 We swap the number at indices i and j.
 
 By condition the number in the interval (i, j)
 are also odd, so no need to do j = i+1 at the
 next iteration. We just do j --> j+1
 
 If j == N, then we don't have more even number
 to swap by, so there is no need to continue
 iterating
 
 */

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int>& A)
    {
        int N = A.size();
        
        
        int j = 1;
        for (int i = 0; i < N && j < N; ++i)
        {
            if (A[i] % 2 == 0)
                continue;
            
            // to handle the case where j = 1 < i,
            // so that we don't begin finding the
            // even integer on the left of i.
            j = max(j, i);
            
            while (j < N && A[j] % 2 != 0)
                ++j;
            
            if (j < N)
                swap(A[i], A[j++]);
        }
        
        return A;
    }
};

int main(void)
{
    vector<int> A{0, 2, 1};
    Solution sol = Solution();
    
    auto res = sol.sortArrayByParity(A);
    
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
