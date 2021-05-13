#include <vector>

using namespace std;



class Solution
{
public:
    
    vector<int> repr;
    vector<int> rank;
    
    int find(int x)
    {
        if (repr[x] == -1)
            return x;
        
        return repr[x] = find(repr[x]);
    }
    
    void unite(int f_a, int f_b)
    {
        if (rank[f_a] < rank[f_b])
            swap(f_a, f_b);
        
        rank[f_a] += rank[f_b];
        repr[f_b] = f_a;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int N = isConnected.size();
        int n_provinces = N;
        
        repr.resize(N, -1);
        rank.resize(N, 1);
        
        for (int i = 0; i != N; ++i)
            for (int j = i+1; j < N; ++j)
                if (isConnected[i][j])
                {
                    int f_a = find(i);
                    int f_b = find(j);
                    
                    if (f_a != f_b)
                    {
                        unite(f_a, f_b);
                        --n_provinces;
                    }
                    
                }
        
        return n_provinces;
    }
};

int main(void)
{
    
}
