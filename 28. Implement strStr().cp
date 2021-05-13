#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution
{
public:
    void compute_lps(const int &p_len, const string &p, vector<int> &lps)
    {
        int i, j;
        
        // i for suffix part
        // j for preffix part
        i = 1;
        j = 0;
        
        while (i < p_len)
        {
            if (p[j] != p[i])
            {
                if (j > 0)
                    j = lps[j-1];
                else
                    ++i;
            }
            else
            {
                lps[i] = j+1;
                ++i;
                ++j;
            }
        }
    }
    
    int strStr(string text, string patt)
    {
        int t_len = text.size();
        int p_len = patt.size();
        
        if (p_len == 0)
            return 0;
        
        vector<int> lps(p_len, 0);
        
        compute_lps(p_len, patt, lps);
        
        int i = 0;
        int k = 0;
        
        while (i < t_len)
        {
            if (patt[k] == text[i])
            {
                if (k == p_len - 1)
                    return i - (p_len - 1);
                else
                {
                    ++i;
                    ++k;
                }
            }
            else
            {
                if (k > 0)
                    k = lps[k-1];
                else
                    ++i;
            }
        }
        
        return -1;
    }
};

int main(void)
{
    string haystack = "hello";
    string needle = "ll";
    
    Solution sol = Solution();
    
    cout << sol.strStr(haystack, needle) << endl;
    
    return 0;
}
