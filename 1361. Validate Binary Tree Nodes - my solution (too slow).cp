#include <vector>
#include <iostream>

using namespace std;

/*
 Idea:
 
 Do DFS checking for cycles (with the help of the check vector)
 and for the existence of forest (with the help of counter).
 
 Complexity:
 - Time: O(2^n)
 - Space: O(n)
 */

enum status
{
    non_visited,
    in_process,
    done
};

class Solution {
public:
    
    int counter = 0;
    bool DFS(const int& u, vector<int>& leftChild, vector<int>& rightChild, vector<status>& check)
    {
        
        check[u] = in_process;
        ++counter;
        
        if (leftChild[u] != -1)
        {
            if (check[leftChild[u]] != non_visited || !DFS(leftChild[u], leftChild, rightChild, check))
                return false;
        }
        
        if (rightChild[u] != -1)
        {
            if (check[rightChild[u]] != non_visited || !DFS(rightChild[u], leftChild, rightChild, check))
                return false;
        }
        
        check[u] = done;
        return true;
        
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        
        for (int u = 0; u != n; ++u)
        {
            vector<status> check(n, non_visited);
            
            if (DFS(u, leftChild, rightChild, check) && counter == n)
                return true;
            
            counter = 0;
        }
        
        return false;
    }
};

int main(void)
{
    vector<int> left{1,-1,3,-1};
    vector<int> right{2,-1,-1,-1};
    int n = 4;
    
    Solution sol = Solution();
    
    cout << int(sol.validateBinaryTreeNodes(n, left, right)) << endl;
    
    return 0;
}
