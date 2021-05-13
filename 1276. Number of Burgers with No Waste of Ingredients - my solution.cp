#include <vector>

using namespace std;

/*
 Pure Math:
 
 Let:
 - J - the number of jumbos
 - S - the amount of smalls.
 
 Given t tomatoes and c cheese we have to find (if exists)
 the quantity of J jumbos and B smalls, such that
 
 4J + 2B = t
  J +  B = c
 
 Use linear algebra:
 
 J = 1/2 * (t - 2c)
 B = 1/2 * (-t + 4c)
 
 J and B have to integers >= 0
 
 For this case the solution exists.
 Otherwise we return {}
 
 Complexity:
 - Time: O(6).
 - Space: O(4).
 
 
 */

class Solution
{
public:
    vector<int> numOfBurgers(int t, int c)
    {
        vector<int> ans;
        
        int total_jumbo_num = t - 2 * c;
        int total_small_num = -t + 4 * c;
        
        if (total_jumbo_num >= 0 && total_jumbo_num % 2 == 0)
            ans.push_back(total_jumbo_num / 2);
        else
            return {};
        
        if (total_small_num >= 0 && total_small_num % 2 == 0)
            ans.push_back(total_small_num / 2);
        else return {};
        
        return ans;
    }
};
