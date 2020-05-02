class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

    if(grid.size() == 0)
    {
        return 0;
    }
    vector<vector<bool>> used(grid.size(), vector<bool>(grid[0].size()));

    vector<vector<vector< pair<int, int> >>> adj(grid.size(), vector<vector<pair<int, int>>>(grid[0].size()));

    vector<vector<int>> offsets = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                pair<int, int> newPoint = make_pair(i + offsets[k][0], j + offsets[k][1]);
                /*
                cout << i << " " << j << ", " << newPoint.first << " " << newPoint.second << "\n";
                if (!(newPoint.first >= 0 && newPoint.first < grid.size()))
                    cout << "first invalid\n";
                else if (!(newPoint.second >= 0 && newPoint.second < grid[0].size()))
                    cout << "second invalid\n";
                else if (!(grid[newPoint.first][newPoint.second] == '1' && grid[i][j] == '1'))
                    cout << "Not Points " << grid[i][j] << ", " << grid[newPoint.first][newPoint.second] << "\n";
                */
                if (newPoint.first >= 0 && newPoint.first < grid.size() && 
                    newPoint.second >= 0 && newPoint.second < grid[0].size() && 
                    grid[newPoint.first][newPoint.second] == '1' && grid[i][j] == '1')
                {
                    adj[i][j].push_back(newPoint);
                }
            }
        }
    }

    int islands = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (!used[i][j] && grid[i][j] == '1')
            {
                islands++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                used[i][j] = true;
                while (q.size())
                {
                    auto front = q.front();
                    q.pop();
                    for (auto nextTo : adj[front.first][front.second])
                    {
                        if (!used[nextTo.first][nextTo.second])
                        {
                            used[nextTo.first][nextTo.second] = true;
                            q.push(nextTo);
                        }
                    }
                }
            }
        }
    }
    return islands;
}
};