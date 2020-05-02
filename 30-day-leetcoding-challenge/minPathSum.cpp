class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        for (int i = (int)grid[0].size() - 1; i >= 1; i--)
        {
            grid[grid.size() - 1][i - 1] += grid[grid.size() - 1][i];
        }
        for (int i = (int)grid.size() - 1; i >= 1; i--)
        {
            grid[i - 1][grid[0].size() - 1] += grid[i][grid[0].size() - 1];
        }

        for (int i = (int)grid.size() - 2; i >= 0; i--)
        {
            for (int j = (int)grid[0].size() - 2; j >= 0; j--)
            {
                grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
            }
        }
        return grid[0][0];
    }
};