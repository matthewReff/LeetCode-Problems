class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> vals;
        
        if(nums.size() == 0)
        {
            return 0;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            vals.insert(nums[i]);
        }
        
        int longest = 1;
        int currLength = 1;
        int current;
        
        auto itr = vals.begin();
        current = (*itr);
        
        itr++;
        while(itr != vals.end())
        {
            if((*itr) == current + 1)
            {
                currLength++;
                if(currLength > longest)
                {
                    longest = currLength;
                }
            }
            else
            {
                currLength = 1;
            }
            current = (*itr);
            itr++;
        }
        return longest;
    }
};
