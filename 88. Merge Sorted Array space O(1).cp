#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int first = m-1;
        int second = n-1;
        
        for (int i = n+m-1; i >= 0 && second >= 0; --i)
        {
            if (first >= 0 && nums1[first] > nums2[second])
                nums1[i] = nums1[first--];
            else
                nums1[i] = nums2[second--];
        }
    }
};

int main(void)
{
    vector<int> nums1{5,6,7,8,9,0,0,0};
    vector<int> nums2{1,2,3};
    
    Solution sol = Solution();
    
    sol.merge(nums1, 5, nums2, 3);
    
    for (auto v :  nums1)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
