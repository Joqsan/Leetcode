#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int>& arr)
    {
        int i = 0;
        int N = arr.size();
        
        // for the first part, check increasing pattern
        while (i+1 < N && arr[i] < arr[i+1])
            ++i;
        
        // if i == 0, then the array is only decreasing, so not mountain
        // if i == N-1, then the array is only increasing, so not mountain
        if (i == 0 || i == N-1)
            return false;
        else //for the second part, check decreasing pattern
            while (i+1 < N && arr[i] > arr[i+1])
                ++i;
        
        return i == N-1;
    }
};

int main(void)
{
    vector<int> arr{2};
    
    Solution sol = Solution();
    
    cout << int(sol.validMountainArray(arr)) << endl;
    
    return 0;
}
