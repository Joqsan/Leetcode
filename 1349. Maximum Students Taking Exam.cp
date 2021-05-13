#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

/*
 
 max(# not cheating seats) = # seats - min(# of cheating seats to remove)
 
 
 1) min(# of cheating seats to remove) = min(# disjoints paths s->u->v->t)
 2) min(# disjoints paths s->u->v->t) = min cut in bipartite graph.
 3) Ford-Fulkerson theorem: min cut in bipartite graph = max flow in bipatite graph.
 4) max flow in bipatite graph = max matching.
 
 Justify the construction of bipartite graph.
 
 
 Complexity:
 - Time: O(V * E^2).
 - Space: O(V * E).
 */
typedef pair<int, int> coor;

class Solution
{
public:
    int seat_counter = 0;
    int s, t;
    int R, C;
    vector<vector<int>> cap;
    
    // left, upper left, lower left, right, upper right, lower right
    vector<coor> dir = {{0,-1},{-1,-1},{1,-1},{0,1},{-1,1},{1,1}};
    
    void build_graph(vector<vector<char>>& seats)
    {
        for (int r = 0; r != R; ++r)
            for (int c = 0; c != C; ++c)
            {
                if (seats[r][c] == '#')
                    continue;
                
                ++seat_counter;
                
                int u = r * C + c;
                
                if (c % 2 == 0)
                {
                    cap[s][u] = 1;
                
                    for (auto [dr, dc] : dir)
                    {
                        int vr = r + dr;
                        int vc = c + dc;
                        
                        if (vr >= 0 && vr < R && vc >= 0 && vc < C)
                            if (seats[vr][vc] == '.')
                            {
                                int v = vr * C + vc;
                                cap[u][v] = 1;
                            }
                    }
                }
                else
                    cap[u][t] = 1;
            }
    }
    
    bool BFS(vector<int>& pred)
    {
        vector<bool> visited(R*C+2, false);
        
        queue<int> Q;
        
        visited[s] = true;
        Q.push(s);
        
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            
            if (u == t)
                return true;
            
            for (int v = 0; v != R*C+2; ++v)
                if (!visited[v] && cap[u][v] == 1)
                {
                    visited[v] = true;
                    pred[v] = u;
                    Q.push(v);
                }
            
            
        }
        
        return false;
        
    }
    
    int maxStudents(vector<vector<char>>& seats)
    {
        R = seats.size();
        C = seats[0].size();
        s = R * C;
        t = R * C + 1;
        cap.resize(R*C+2, vector<int>(R*C+2, 0));
        
        build_graph(seats);
        
        vector<int> pred(R*C+2, -1);
        int max_flow = 0;
        
        while (BFS(pred))
        {
            ++max_flow;
            
            for (int v = t; v != s; v = pred[v])
            {
                int u = pred[v];
                
                --cap[u][v];
                ++cap[v][u];
            }
            
            pred.resize(C, -1);
        }
        
        return seat_counter - max_flow;
    }
};

int main(void)
{
    vector<vector<char>> seats{{'#','.','#','#','.','#'},{'.','#','#','#','#','.'},{'#','.','#','#','.','#'}};
    
    Solution sol = Solution();
    
    cout << sol.maxStudents(seats) << endl;
    
    return 0;
}
