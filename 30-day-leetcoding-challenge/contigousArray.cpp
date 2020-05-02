class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;
        vector<int> sums(nums.size());
        if (nums[0] == 1)
            sums[0] = 1;
        else
            sums[0] = -1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                sums[i] = sums[i - 1] + 1;
            else
                sums[i] = sums[i - 1] - 1;
        }

        map<int, vector<int>> tracker;
        tracker[0].push_back(-1);
        for (int i = 0; i < sums.size(); i++)
        {
            tracker[sums[i]].push_back(i);
        }
        int longest = 0;
        auto itr = tracker.begin();
        while (itr != tracker.end())
        {
            if (itr->second.size() > 1)
            {
                int length = itr->second[itr->second.size() - 1] - itr->second[0];
                if (length > longest)
                {
                    longest = length;
                }
            }
            itr++;
        }
        return longest;
    }
};