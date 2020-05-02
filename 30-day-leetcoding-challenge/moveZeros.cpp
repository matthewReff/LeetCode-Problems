class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int validIndex = 0;
        int numZeros = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                numZeros++;
            }
            else
            {
                nums[validIndex] = nums[i];
                validIndex++;
            }
        }
        
        for(int i = nums.size() - numZeros; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};