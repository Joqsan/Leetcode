#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

class Solution
{
public:
    
    int partition(vector<int>& nums, int l, int r)
    {
        int t = l + rand() % (r - l + 1);
        
        swap(nums[t], nums[r]);
        
        int pivot = nums[r];
        int i = l - 1; // pointer to one less the position of the last > pivot
        
        for (int j = l; j != r; ++j)
            if (nums[j] >= pivot)
            {
                ++i;
                swap(nums[i], nums[j]);
            }
        
        swap(nums[i+1], nums[r]);
        
        return i+1;
    }
    
    int quicksort(vector<int>& nums, int l, int r, int k)
    {
        if (l == r)
            return nums[l];
        
        int q = partition(nums, l, r);
        
        int i = q - l + 1;
        
        if (i == k-1)
            return nums[q];
        else if (i < k)
            return quicksort(nums, l, q-1, k);
        else
            return quicksort(nums, q+1, r, k-i);
    }
    
    int findKthLargest(vector<int>& nums, int k)
    {
        return quicksort(nums, 0, nums.size()-1, k);
    }
};


int main(void)
{
    vector<int> nums{3,2,3,1,2,4,5,5,6};
    int k = 4;
    
    Solution sol = Solution();
    
    cout << sol.findKthLargest(nums, k) << endl;
    
    return 0;
}
