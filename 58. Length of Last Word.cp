#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int i = s.size() - 1;
        
        // strip all whitespaces at the end
        while (i >= 0 && s[i] == ' ')
            --i;
        
        int j = i;
        
        // traverse to the left until first whitespace
        // found
        while (i >= 0 && s[i] != ' ')
            --i;
        
        return j - i;
    }
};
