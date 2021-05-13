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


struct TreeNode
{
    int val;
    TreeNode *parent = nullptr;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};


// Binary tree property
// (less than x) <- x -> (greater than x)
class Tree
{
private:
    vector<TreeNode> binaryTree;
    
    
    void Transplant(TreeNode *u, TreeNode *v);
    
    void InOrder(TreeNode *x);
    void PostOrder(TreeNode *x);
    void PreOrder(TreeNode *x);
    
public:
    
    Tree(void);
    TreeNode *root;
    
    void InOrder(void);
    void PostOrder(void);
    void PreOrder(void);
    
    TreeNode* Search(int val);
    
    TreeNode* Minimum(TreeNode *x);
    TreeNode* Maximum(TreeNode *x);
    TreeNode* Successor(TreeNode *x);
    
    void Insert(int val);
    void Delete(int val);
    int FindDepth(TreeNode *x);
};

Tree::Tree(void)
{
    root = nullptr;
}


void Tree::Insert(int val)
{
    TreeNode *p = nullptr;// t : traverse
    TreeNode *t = root;
    
    while (t != nullptr)
    {
        p = t;
        if (val < t->val)
            t = t->left;
        else
            t = t->right;
    }
    
    // At this point we've found the place for z
    // Update parent of z
    TreeNode *z = new TreeNode;
    z->parent = p;
    z->val = val;
    
    if (p == nullptr)
        root = z;
    else if (val < p->val)
        p->left = z;
    else
        p->right = z;
}

//
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};

int FindDepth(TreeNode *x)
{
    if (x == nullptr)
        return 0;
    
    int depth = 0;
    
    if (x->left != nullptr)
        depth = max(depth, FindDepth(x->left));
    
    if (x->right != nullptr)
        depth = max(depth, FindDepth(x->right));
    
    return depth + 1;
}

class Solution
{
public:
    Solution(void) = default;
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (!root)
            return {};
        
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> Q;
        
        Q.push({root, 0});
        
        while (!Q.empty())
        {
            auto [pnode, depth] = Q.front();
            Q.pop();
            
            if (ans.size() < depth + 1)
                ans.push_back({});
            
            ans[depth].push_back(pnode->val);
            
            if (pnode->left)
                Q.push({pnode->left, depth+1});
            if (pnode->right)
                Q.push({pnode->right, depth+1});
        }
        
        return ans;
    }
};

int main(void)
{
    Tree tree = Tree();
    Solution sol = Solution();
    
    tree.Insert(12);
    tree.Insert(5);
    tree.Insert(2);
    tree.Insert(9);
    tree.Insert(18);
    tree.Insert(15);
    tree.Insert(19);
    tree.Insert(13);
    tree.Insert(17);
    
    auto res = sol.levelOrder(tree.root);
    
    for (auto level : res)
    {
        for (auto v : level)
            cout << v << " ";
        
        cout << endl;
    }
    
//    cout << tree.FindDepth(tree.root) << endl;
    
    return 0;
}



