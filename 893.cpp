class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        map<pair<string, string>, int> processed;
        
        for(int i = 0; i < A.size(); i++)
        {
            string evens;
            string odds;
            for(int j = 0; j < A[i].size(); j++)
            {
                if(j % 2 == 0)
                {
                    evens.push_back(A[i][j]);
                }   
                else
                {
                    odds.push_back(A[i][j]);
                }
            }
            sort(evens.begin(), evens.end());
            sort(odds.begin(), odds.end());
            processed[make_pair(evens, odds)]++;
        }
        
        return processed.size();
    }
};