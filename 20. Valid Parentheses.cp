#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, char> smap {
    {')', '('},
    {']', '['},
    {'}', '{'}
};


class Solution
{
public:
    Solution(void) = default;
    
    bool isValid(string s)
    {
        stack<char> Q;
        
        bool ok = true;
        for (int i = 0; i != s.size() && ok; ++i)
        {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[')
                Q.push(c);
            else if (Q.empty() || smap[c] != Q.top())
            {
                ok = false;
                break;
            }
            else
                Q.pop();
        }
        
        return (!Q.empty() && ok) ? false : ok;
    }
};

int main(void)
{
    string s = "[";
    Solution sol = Solution();
    
    cout << sol.isValid(s) << endl;
    
    return 0;
}
