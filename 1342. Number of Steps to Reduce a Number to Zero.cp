#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int n_op = 0;
        while (num)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
                --num;
            
            ++n_op;
        }
        
        return n_op;
        
    }
};
