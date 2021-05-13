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
        int N = s.size();
        
        vector<int> ans(N);
        
        // Compute the right distances for a
        // fixed position of the character c
        
        // Initialization position
        int last_c_pos = -N;
        for (int i = 0; i != N; ++i)
        {
            if (s[i] == c)
                last_c_pos = i;
            
            ans[i] = i - last_c_pos;
        }
        
        // At this point last_c_pos points to
        // the las c encountered. All character
        // to the right of c already have their
        // final distance, so no need to start
        // from index n-1.
        for (int i = last_c_pos-1; i >= 0; --i)
        {
            if (s[i] == c)
                last_c_pos = i;
            
            ans[i] = min(ans[i], last_c_pos - i);
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
