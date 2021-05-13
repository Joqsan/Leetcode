#include <unordered_map>
#include <string>
#include <vector>

using namespace std;



class Solution
{
public:
    
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue)
    {
        unordered_map<string, int> hmap;
        hmap["type"] = 0;
        hmap["color"] = 1;
        hmap["name"] = 2;
        
        int counter = 0;
        for (auto item : items)
            if (item[hmap[ruleKey]] == ruleValue)
                ++counter;
        
        return counter;
    }
};
