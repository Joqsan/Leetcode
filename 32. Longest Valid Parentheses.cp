#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


/*
 
 Idea:
 - Traverse the string from left to right and then from right to left.
 - Sweep from left to right: It check only for the case where the right
    parentheses are more than the left ones.
    - If at s[i] the # of right > than left, then for k in [0, i] that
        situation won't change, so set left = right = 0.
 - Sweep from right to left: It check the same for the case # left > # right.
 
 Complexity:
 - Time: O(n).
 - Space: O(1).
 
 */
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int left = 0, right = 0;
        int max_len = 0;
        
        //left to right
        for (auto c : s)
        {
            if (c == '(')
                ++left;
            else
                ++right;
            
            if (left == right)
                max_len = max(max_len, 2*left);
            else if (right > left)
                left = right = 0;
        }
        
        //right to left
        left = right = 0;
        for (int i = s.size()-1; i >= 0; --i)
        {
            if (s[i] == '(')
                ++left;
            else
                ++right;
            
            if (left == right)
                max_len = max(max_len, 2*left);
            else if (left > right)
                left = right = 0;
        }
        
        return max_len;
    }
};

int main(void)
{
    string s = "(()";
    
    Solution sol = Solution();
    
    cout << sol.longestValidParentheses(s) << endl;
    
    return 0;
}
