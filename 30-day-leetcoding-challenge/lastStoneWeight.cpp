class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    multiset<int, greater<int>> stoneSet;
    for (int i = 0; i < stones.size(); i++)
    {
        stoneSet.insert(stones[i]);
    }

    while (stoneSet.size() > 1)
    {
        auto itr = stoneSet.begin();
        auto itr2 = itr;
        itr2++;
        auto val1 = (*itr);
        auto val2 = (*itr2);
        stoneSet.erase(itr);
        stoneSet.erase(itr2);
        if (val1 != val2)
            stoneSet.insert(max(val1, val2) - min(val1, val2));
    }

    if (stoneSet.size() == 1)
        return (*stoneSet.begin());
    else
        return 0;
    }
};