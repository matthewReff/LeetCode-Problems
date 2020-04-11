class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
    map<vector<int>, int> pointMap;
    for (int i = 0; i < points.size(); i++)
    {
        pointMap[points[i]]++;
    }
    if (pointMap.size() <= 2)
    {
        int total = 0;
        for (auto val : pointMap)
        {
            total += val.second;
        }
        return total;
    }
    int maxVal = 1;
    for (auto itr = pointMap.begin(); itr != pointMap.end(); itr++)
    {
        auto itr2 = itr;
        itr2++;
        map < pair<int, int>, int> slopes;
        for (; itr2 != pointMap.end(); itr2++)
        {
            auto pair1 = itr->first;
            auto pair2 = itr2->first;
            int rise = pair1[1] - pair2[1];
            int run = pair1[0] - pair2[0];
            if (run == 0)
                slopes[make_pair(pair1[0], 2147483647)] += itr2->second;
            else
            {
                int gcdNum = gcd(rise, run);
                if (gcdNum == 0)
                    gcdNum = 1;
                rise /= gcdNum;
                run /= gcdNum;
                slopes[make_pair(rise, run)] += itr2->second;
            }
        }

        auto slopeitr = slopes.begin();
        while (slopeitr != slopes.end())
        {
            if (maxVal < slopeitr->second + itr->second)
            {
                maxVal = slopeitr->second + itr->second;
            }
            slopeitr++;
        }
    }
    return maxVal;
    }
};