#include <vector>
#include <stack>
#include <utility>

using namespace std;


class Solution
{
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        stack<pair<int, int>> Q;
        int R = image.size();
        int C = image[0].size();
        
        int initial_color = image[sr][sc];
        
        Q.push({sr, sc});
        
        while (!Q.empty())
        {
            auto [r, c] = Q.top();
            Q.pop();
            
            if (image[r][c] == newColor)
                continue;
            
            image[r][c] = newColor;
            
            for (auto shift : {-1, 1})
            {
                if (r + shift >= 0 && r + shift < R && image[r+shift][c] == initial_color)
                    Q.push({r+shift, c});
                
                if (c + shift >= 0 && c + shift < C && image[r][c+shift] == initial_color)
                    Q.push({r, c+shift});
            }
        }
        
        return image;
    }
};

int main(void)
{
    
}
