#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    Solution(void) = default;
    
    int countSubstrings(string s)
    {
        int N = s.size();
        
        if (N <= 1)
            return N;
        
        vector<vector<bool>> p(N, vector<bool>(N));
        int pal_counter = N;
        for (int i = 0; i != N; ++i)
        {
            p[i][i] = true;
            if (s[i] == s[i+1])
            {
                ++pal_counter;
                p[i][i+1] = true;
            }
        }
        
        // j : offset
        for (int j = 2; j != N; ++j)
            for (int i = 0; i != N-j; ++i)
            {
                int a = i; // start
                int b = i + j; // end
                
                if (p[a+1][b-1] && s[a] == s[b])
                {
                    p[a][b] = true;
                    ++pal_counter;
                }
            }
        
        return pal_counter;
    }
};

int main(void)
{
    string s = "a";
    Solution sol = Solution();
    
    cout << sol.countSubstrings(s) << endl;
    
    return 0;
    
}
