class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> ans;
        vector<vector<string>> retArr;
        for(int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            ans[temp].push_back(strs[i]);
        }
        for(auto thing : ans)
        {
            retArr.push_back(thing.second);
        }
        return retArr;
    }
};