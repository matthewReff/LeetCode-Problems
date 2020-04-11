class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> retVal(2);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i != j && nums[i] + nums[j] == target)
                {
                    retVal[0] = i;
                    retVal[1] = j;
                    return retVal;
                }
            }
        }
        return retVal;
    }
};