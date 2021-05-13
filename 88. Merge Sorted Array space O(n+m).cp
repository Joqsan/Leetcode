#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> aux(m+n);
        
        int i = 0;
        int j = 0;
        int k = 0;
        while (i != m && j != n)
        {
            if (nums1[i] <= nums2[j])
                aux[k++] = nums1[i++];
            else
                aux[k++] = nums2[j++];
        }
        
        while (i != m)
            aux[k++] = nums1[i++];
        
        while (j != n)
            aux[k++] = nums2[j++];
        
        nums1 = aux;
    }
};

int main(void)
{
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};
    
    Solution sol = Solution();
    
    sol.merge(nums1, 3, nums2, nums2.size());
    
    for (auto v :  nums1)
        cout << v << " ";
    cout << endl;
    
    return 0;
}
