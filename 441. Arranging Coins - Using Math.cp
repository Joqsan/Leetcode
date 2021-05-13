#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        return (int)(sqrt(2*double(n) + 0.25) - 0.5);
    }
};

int main(void)
{
    int n = 8;
    Solution sol = Solution();
    
    cout << sol.arrangeCoins(n) << endl;
}
