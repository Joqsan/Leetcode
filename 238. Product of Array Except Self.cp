#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    Solution(void) = default;
    
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> left(n);
        
        left[0] = 1;
        for (int i = 1; i != n; ++i)
            left[i] = left[i-1] * nums[i-1];
        
        int right = 1;
        for (int i = n-1; i >= 0; --i)
        {
            left[i] = left[i] * right;
            
            right *= nums[i];
        }
        
        return left;
    }
};

int main(void)
{
    vector<int>a{1, 5, 17, 20, 0, 1, 0, 2, 10, 0};
    
    Solution sol = Solution();
    
    auto result = sol.productExceptSelf(a);
    
    for (auto v : result)
        cout << v << " ";
    
    cout << endl;
    
    return 0;
}
