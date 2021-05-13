#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    string restoreString(string s, vector<int>& indices)
    {
        string ss(s.size(), '-');
        
        for (int i = 0; i != s.size(); ++i)
            while (indices[i] != i)
            {
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]);
            }
        
        return s;
    }
};

int main(void)
{
    string s = "aiohn";
    vector<int> ind{3,1,4,2,0};
    
    Solution sol = Solution();
    
    cout << sol.restoreString(s, ind) << endl;
    
    return 0;
}
