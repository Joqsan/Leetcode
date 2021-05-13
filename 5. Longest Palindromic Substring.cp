#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    Solution(void) = default;
    
    string longestPalindrome(string s)
    {
        int N = s.size();

        if (N == 1)
            return s;

        vector<vector<bool>> p(N, vector<bool>(N, false));
        int pal_len = 1;
        int pal_start = 0;

        for (int i = 0; i != N-1; ++i)
        {
            p[i][i] = true;

            if (s[i] == s[i+1])
            {
                p[i][i+1] = true;
                pal_start = i;
                pal_len = 2;
            }
        }

        p[N-1][N-1] = true;

        // Above we find p[i][j] for substring of
        // length 1 and 2. Below we do the same for
        // subtrings of length 3, 4, and so on
        // j : iteration by length after starting position
        // i : iteration by starting position
        for (int j = 2; j != N; ++j)
            for (int i = 0; i != N-j; ++i)
            {
                int t0 = i;
                int t1 = i+j;

                if (p[t0+1][t1-1] && s[t0] == s[t1])
                {
                    p[t0][t1] = true;
                    //because the length increase with j
                    //below we don't need max()
                    pal_start = i;
                    pal_len = j + 1;
                }
            }
        return s.substr(pal_start, pal_len);
    }
};

int main(void)
{
    string s = "acaba";
    
    Solution sol = Solution();
    
    cout << sol.longestPalindrome(s) << endl;
    
    return 0;
}
