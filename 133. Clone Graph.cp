#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

 class Node
{
 public:

    int val;
    vector<Node*> neighbors;
    
    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
        
    }
    
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
        
    }
    
    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
        
    }
 };

/*
 We use the map vertex for both storing the
 new nodes and for checking is a node was already
 visited or not:
 
 - If a node u hasn't been visited, then it means that
 1) It's not in vertex (in vertex its value is nullptr)
 2) We have to explore its adjacency list.
 
 So we add it to the map (to solve 1)) and push it to the
 queue (to account for 2))
 
 Once making sure that all nodes in the adjacency list of
 u are created we add them to the vector of neighbors
 
 */

class Solution
{
public:
    Node* cloneGraph(Node* node)
    {
        
        // Corner case
        if (!node)
            return nullptr;
        
        unordered_map<int, Node*> vertex;
        
        queue<Node*> Q;
        
        Node* new_root = new Node(node->val);
        vertex[node->val] = new_root;
        
        Q.push(node);
        
        while (!Q.empty())
        {
            Node* u = Q.front();
            Q.pop();
            
            for (auto v : u->neighbors)
            {
                if (!vertex[v->val])
                {
                    vertex[v->val] = new Node(v->val);
                    Q.push(v);
                }
                
                vertex[u->val]->neighbors.push_back(vertex[v->val]);
            }
        }
    
        return new_root;
        
    }
};

int main(void)
{
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    
    one->neighbors = {two, four};
    two->neighbors = {one, three};
    three->neighbors = {two, four};
    four->neighbors = {one, three};
    
    Solution sol = Solution();
    
    auto res = sol.cloneGraph(one);
    
    return 0;
    
}
