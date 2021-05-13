#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string res;
        
        for (auto s : address)
        {
            if (s != '.')
                res = res + s;
            else
                res = res + "[.]";
        }
        
        return res;
        
    }
};
