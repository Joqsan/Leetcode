#include <iostream>
#include <numeric>

using namespace std;


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version, int bad)
{
    if (version >= bad)
        return true;
    else
        return false;
}


class Solution
{
public:
    Solution(void) = default;
    int firstBadVersion(int n, int bad)
    {
        unsigned int l = 0;
        unsigned int r = n;
        
        while (l <= r)
        {
            unsigned int m = (l + r) / 2;
            
            if (isBadVersion(m, bad))
                r = m-1;
            else
                l = m+1;
        }
        
        return l;
    }
};

int main(void)
{
    int n = 2126753390;
    int bad = 1702766719;
    
    Solution sol = Solution();
    
    
    cout << sol.firstBadVersion(n, bad) << endl;
    
    return 0;
}
