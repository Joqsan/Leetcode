#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        for (int i = n-1; i >= 0; --i)
        {
            int k = m-2;
            int last = nums1[m-1];
            
            // Insertion sort-like function
            while (k >= 0 && nums1[k] > nums2[i])
            {
                nums1[k+1] = nums1[k];
                --k;
            }
            
            // if we move element up or if
            // we don't move anything but last > nums2[i]
            if (k != m-2 || last > nums2[i])
            {
                nums1[k+1] = nums2[i];
                nums2[i] = last;
            }
        }
        
        for (int i = m; i != n+m; ++i)
            nums1[i] = nums2[i-m];
    }
};

int main(void)
{
    vector<int> nums1{0};
    vector<int> nums2{1};
    
    Solution sol = Solution();
    
    sol.merge(nums1, 0, nums2, 1);
    
    for (auto v :  nums1)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
