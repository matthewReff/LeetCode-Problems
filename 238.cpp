class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftArr(nums.size(), 0);
        vector<int> rightArr(nums.size(), 0);
        vector<int> ans(nums.size(), 0);
        
        leftArr[0] = nums[0];
        for(int i = 1; i < (int)nums.size(); i++)
        {
            leftArr[i] = leftArr[i-1] * nums[i];
        }
        
        rightArr[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = (int)nums.size() - 2; i >= 0; i--)
        {
            rightArr[i] = rightArr[i+1] * nums[i];
        }
        
        ans[0] = rightArr[1];
        ans[nums.size() - 1] = leftArr[nums.size() - 2];
        for(int i = 1; i < nums.size() - 1; i++)
        {
            ans[i] = leftArr[i-1] * rightArr[i+1];
        }
        return ans;
    }
};