#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    Solution(void) = default;
    
    
    int getImportance(vector<Employee*> employees, int id)
    {
        
        auto it = find_if(employees.begin(), employees.end(),
                          [id](const Employee* a){return a->id == id;});
        
        int total_importance = 0;
        queue<Employee*> Q;
        vector<bool> visited(2000, false);
        
        visited[(*it)->id] = true;
        Q.push(*it);
        
        while (!Q.empty())
        {
            auto u = Q.front();
            Q.pop();
            
            total_importance += u->importance;
            
            for (auto v : u->subordinates)
                if (!visited[v])
                {
                    auto it = find_if(employees.begin(), employees.end(),
                                      [v](const Employee* a){return a->id == v;});
                    visited[v] = true;
                    Q.push(*it);
                }
        }
        
        return total_importance;
    }
};


int main(void)
{
    Employee a{1, 7, {2}};
    Employee b{2, 5, {}};
//    Employee c{3, 3, {}};
    
//    vector<Employee*> employees{&a, &b, &c};
    vector<Employee*> employees{&b, &a};
    int id = 2;
    
    Solution sol = Solution();
    
    cout << sol.getImportance(employees, id) << endl;
    
    return 0;
}
