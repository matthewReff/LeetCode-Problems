class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> used;
        int retVal;
        for(int i = 0; i < nums.size(); i++)
        {
            used[nums[i]]++;
        }
        
        auto itr = used.begin();
        while(itr != used.end())
        {
            if(itr->second == 1)
            {
                retVal = itr->first;
                break;
            }
            itr++;
        }
        
        return retVal;
    }
};