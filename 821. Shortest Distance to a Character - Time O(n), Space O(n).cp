#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;


class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n = s.size();
        
        vector<int> e_pos(1, INT32_MAX);
        vector<int> ans(n);
        
        for (int i = 0; i != n; ++i)
            if (s[i] == c)
                e_pos.push_back(i);
        
        e_pos.push_back(INT32_MAX);
        int k = 0;
        for (int i = 1; i != e_pos.size(); ++i)
        {
            int low = e_pos[i-1];
            int upp = e_pos[i];
            
            while (k < n && k < upp)
            {
                ans[k] = min(abs(k - low), abs(k - upp));
                ++k;
            }
        }
        
        return ans;
    }
};

int main(void)
{
    string s = "loveleetcode";
    char c = 'e';
    
    Solution sol = Solution();
    
    auto res = sol.shortestToChar(s, c);
    
    for (auto v : res)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
