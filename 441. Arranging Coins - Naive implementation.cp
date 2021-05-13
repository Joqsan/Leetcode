#include <iostream>

using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int counter = 0;
        for (int row = 1; row <= n && n >= 0; ++row)
        {
            ++counter;
            n -= row;
        }
        
        return counter;
    }
};

int main(void)
{
    int n = 5;
    Solution sol = Solution();
    
    cout << sol.arrangeCoins(n) << endl;
}
