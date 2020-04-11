class Solution {
public:
    int equalSubstring(string s, string t, int maxCost)
{
    vector<int> cost(s.size(), 0);
    vector<int> sumCost(s.size(), 0);

    for (int i = 0; i < s.size(); i++)
    {
        cost[i] = abs(s[i] - t[i]);
    }

    int lastTotal = 0;
    int maxLength = 0;
    int i = 0;
    int j = 0;
    while (i != s.size() && j != s.size())
    {
        int currentTotal = lastTotal;
        while (j != s.size() && currentTotal + cost[j] <= maxCost)
        {
            currentTotal += cost[j];
            j++;
        }
        if (j - i > maxLength)
            maxLength = j - i;
        if (i == j)
        {
            lastTotal = 0;
            j++;
        }
        else
            lastTotal = currentTotal - cost[i];
        i++;
    }
    return maxLength;
    }
};