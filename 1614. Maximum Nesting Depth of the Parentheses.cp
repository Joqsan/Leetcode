#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int counter = 0;
        int max_depth = 0;
        
        for (auto c : s)
        {
            if (c == '(')
            {
                ++counter;
                max_depth = max(max_depth, counter);
            }
            else if (c == ')')
                --counter;
        }
        
        return max_depth;
    }
};
