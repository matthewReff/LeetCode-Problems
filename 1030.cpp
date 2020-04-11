class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<pair< int, pair<int, int>>> answer;
        
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                answer.push_back(make_pair(abs(i - r0) + abs(j - c0), make_pair(i, j)));
            }
        }
          sort(answer.begin(), answer.end());
        vector<vector<int>> returnArr;
        for(auto thing : answer)
        {
            vector<int> pairVal;
            pairVal.push_back(thing.second.first);
            pairVal.push_back(thing.second.second);
            returnArr.push_back(pairVal);
        }
    return returnArr;
    }
  
};