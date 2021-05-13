#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    Solution(void) = default;
    
    string maxPal(string &s, int start) {
        // support variables
        int len = s.size(), i = start - 1, j = start + 1;
        // adjusting for repeated central character
        // first case: i and start point to the same char
        while (i > -1 && s[i] == s[start]) i--;
        // second case: j and start point to the same char
        while (j < len && s[j] == s[start]) j++;
        while (i > -1 && j < len) {
            if (s[i] == s[j]) i--, j++;
            else break;
        }
        return s.substr(i + 1, j - i - 1);
    }
    string longestPalindrome(string s) {
        // support variables
        int i = s.size() >> 1, j = i + 1, resLen = 1;
        string res = string(1, s[0]), tmp;
        while (i) {
            // searching around i
            tmp = maxPal(s, i--);
            if (tmp.size() > resLen) {
                resLen = tmp.size();
                res = tmp;
            }
            // searching around j
            tmp = maxPal(s, j++);
            if (tmp.size() > resLen) {
                resLen = tmp.size();
                res = tmp;
            }
            if (i < resLen / 2) break;
        }
        return res;
    }
};

int main(void)
{
    string s = "acaba";
    
    Solution sol = Solution();
    
    cout << sol.longestPalindrome(s) << endl;
    
    return 0;
}

