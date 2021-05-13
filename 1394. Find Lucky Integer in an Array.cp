#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


 
 
 
 
 
/* This was a bit faster
class Solution
{
public:
    int findLucky(vector<int>& arr)
    {
        vector<int> num_to_count(501, 0);
        int ans = -1;
        for (auto a : arr)
            num_to_count[a]++;
        
        for (auto a : arr)
            if (a == num_to_count[a])
                ans = max(ans, a);
        
        return ans;
    }
};
 */

class Solution
{
public:
    int findLucky(vector<int>& arr)
    {
        vector<int> num_to_count(501, 0);
        int ans = -1;
        for (auto a : arr)
            num_to_count[a]++;
        
        for (auto a : arr)
            if (a == num_to_count[a])
                ans = max(ans, a);
        
        return ans;
    }
};

int main(void)
{
    
}
