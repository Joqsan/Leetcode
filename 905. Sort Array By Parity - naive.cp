#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int>& A)
    {
        int N = A.size();
        
        for (int i = 0; i != N; ++i)
        {
            if (A[i] % 2 == 0)
                continue;
            
            int j = i+1;
            
            while (j < N && A[j] % 2 != 0)
                ++j;
            
            if (j < N)
                swap(A[i], A[j]);
        }
        
        return A;
    }
};

int main(void)
{
    vector<int> A{3,1,2,4};
    Solution sol = Solution();
    
    auto res = sol.sortArrayByParity(A);
    
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
