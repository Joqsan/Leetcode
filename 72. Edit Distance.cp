#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    Solution(void) = default;
    int minDistance(string word1, string word2)
    {
        int M = word1.size();
        int N = word2.size();
        
        // we include a row and a column for an empty string
        vector<vector<int>> distance(M+1, vector<int>(N+1, 0));
        
        // if word1 is empty we have to make N insertions
        for (int i = 1; i != N+1; ++i)
            distance[0][i] = i;
        
        // if word2 is empty we have to make M insertions
        for (int i = 1; i != M+1; ++i)
            distance[i][0] = i;
        
        // we begin from a=1,b=1, since a=0 and b=0
        // are reserved for the empty strings.
        for (int a = 1; a != M+1; ++a)
            for (int b = 1; b != N+1; ++b)
            {
                int c = (word1[a-1] == word2[b-1]) ? 0 : 1;
                
                distance[a][b] = min(
                                     min(distance[a][b-1]+1, distance[a-1][b]+1),
                                     distance[a-1][b-1] + c
                );
                
            }
        
        return distance[M][N];
    }
};


int main(void)
{
    string word1 = "intention";
    string word2 = "execution";
    
    Solution sol = Solution();
    
    cout << sol.minDistance(word1, word2) << endl;
    
    return 0;
}
