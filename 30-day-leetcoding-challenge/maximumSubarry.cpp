class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> kadane(nums.size());
        int maxVal = nums[0];
        if(nums[0] < 0)
        {
            kadane[0] = 0;
        }
        else
        {
            kadane[0] = nums[0];
        }
        for(int i = 1; i < nums.size(); i++)
        {
            int newVal = kadane[i-1] + nums[i]; 
            if(newVal > 0)
            {
                kadane[i] = newVal; 
            }
            else
            {
                kadane[i] = 0;
            }
            maxVal = max(maxVal, newVal);
        }
        return maxVal;
    }
};