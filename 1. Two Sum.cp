#include <iostream>
#include <map>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(void) = default;
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // first: number, second: its index
        unordered_map<int, int> imap;
        
        for (int i = 0;; ++i)
        {
            auto it = imap.find(target - nums[i]);
            
            if (it != imap.end())
                return {it->second, i};
            else
                imap[nums[i]] = i;
        
        }
    }
    
};

int main(void)
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for (int i=0; i != n; ++i)
        cin >> a[i];
    
    int target;
    
    cin >> target;
    
    Solution solve;
    
    vector<int> result = solve.twoSum(a, target);
    
    cout << result[0] << " " << result[1] << endl;
    
    return 0;
}
