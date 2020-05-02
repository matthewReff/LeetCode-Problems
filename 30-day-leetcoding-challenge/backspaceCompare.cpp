class Solution {
public:
    bool backspaceCompare(string S, string T) {
    string tempString = "";
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '#')
        {
            if (tempString.size())
            {
                tempString.erase(tempString.begin() + tempString.size() - 1, tempString.end());
            }
        }
        else
            tempString.push_back(S[i]);
    }
    S = tempString;

    tempString = "";
    for (int i = 0; i < T.size(); i++)
    {
        if (T[i] == '#')
        {
            if (tempString.size())
            {
                tempString.erase(tempString.begin() + tempString.size() - 1, tempString.end());
            }
        }
        else
            tempString.push_back(T[i]);
    }
    T = tempString;
    return S == T;
    }
};