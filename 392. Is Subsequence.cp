#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int M = t.size();
        int i = 0;
        
        for (int j = 0; j != M; ++j)
            if (s[i] == t[j])
                ++i;
        
        if (i == s.size())
            return true;
        else
            return false;
    }
};

int main(void)
{
    string s = "ago";
    string t = "ahbgdc";
    
    Solution sol = Solution();
    
    cout << int(sol.isSubsequence(s, t)) << endl;
    
    return 0;
}
