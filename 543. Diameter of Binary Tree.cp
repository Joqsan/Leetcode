#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;


/**
 * Definition for a binary tree TreeNode.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int FindDepth(TreeNode *x, int &diameter)
{
    // if x == nullptr, it doesn't provide
    // any contribution to its parent depth
    if (x == nullptr)
        return -1;
    
    int depth_l = FindDepth(x->left, diameter);
    int depth_r = FindDepth(x->right, diameter);
    
    // The height of a tree is the max number
    // of edges going down.
    // When we have the maximum height of the left
    // and right subtree we have to include the 2
    // edges connecting them to the root, that's
    // why we have + 2 below
    diameter = max(diameter, depth_l + depth_r + 2);
    
    return max(depth_l, depth_r) + 1;
}


int main(void)
{
//    vector<int> nums{1,2,3,4,5};
    vector<int> nums{16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    vector<TreeNode*> p;
    
    
    
    for (int i = 0; i != nums.size(); ++i)
    {
        p.push_back(new TreeNode(nums[i]));
    }
    
    for (int i = 0; i != nums.size()/2; ++i)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        p[i]->left = p[left];
        p[i]->right = p[right];
    }
    
    int diameter = 0;
    
    cout << FindDepth(p[0], diameter) << endl;
    
    cout << diameter << endl;
    
    return 0;
}



