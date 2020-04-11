class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string returnString = "";
        
        if(strs.size() == 0)
        {
            return "";
        }
        
        for(int j = 0; j < strs[0].size(); j++)
        {
            char thisChar = strs[0][j];
            for(int i = 0; i < strs.size(); i++)
            {
                if(j >= strs[i].size() || strs[i][j] != thisChar)
                {
                    return returnString;
                }
            }
            returnString += thisChar;
        }
        return returnString;
    }
};