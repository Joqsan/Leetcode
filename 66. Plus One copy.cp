#include <vector>
#include <iostream>

using namespace std;




class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int N = digits.size();
        vector<int> ans(N+1, 0);
        
        ans[N] = (digits[N-1] + 1) % 10;
        int overflow = (digits[N-1] + 1) / 10;
        for (int i = N-2; i >= 0; --i)
        {
            ans[i+1] = (overflow + digits[i]) % 10;
            overflow = (overflow + digits[i]) / 10;
        }
        
        if (overflow)
            ans[0] = overflow;
        else
            ans.erase(ans.begin());
        
        return ans;
    }
};

int main(void)
{
    vector<int> digits{9, 9, 9};
    
    Solution sol = Solution();
    
    auto res = sol.plusOne(digits);
    
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
