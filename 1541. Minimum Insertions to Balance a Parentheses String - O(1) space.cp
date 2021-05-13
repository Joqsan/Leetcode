#include <string>
#include <stack>
#include <iostream>


using namespace std;

/*
 
 Case       Stack       Array       Counter     Index
 1          (           ))          -           i -> i
 2          (           )(          +1          i -> i+1
 3          empty       ))          +1          i -> i+1
 4          empty       )(          +2          i -> i
 
 */

class Solution
{
public:
    int minInsertions(string s)
    {
        s = s + '.';
        int counter = 0;
        int n_open = 0;
        
        for (int i = 0; i != s.size()-1; ++i)
        {
            if (s[i] == '(')
                ++n_open;
            else
            {
                if (n_open == 0)
                {
                    //Case 4
                    if (s[i+1] != ')')
                        counter += 2;
                    else // Case 1
                    {
                        ++counter;
                        ++i;
                    }
                }
                else
                {
                    --n_open;
                    
                    // Case 1
                    if (s[i+1] == ')')
                        ++i;
                    else // Case 2
                        ++counter;
                }
            }
        }
        
        while (n_open > 0)
        {
            counter += 2;
            --n_open;
        }
        
        return counter;
    }
};


int main(void)
{
    string s = ")))))))";
    
    Solution sol = Solution();
    
    cout << sol.minInsertions(s) << endl;
    
    return 0;
}
