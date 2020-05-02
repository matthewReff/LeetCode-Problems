class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        vector<int> sums(nums.size() + 1, 0);
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            sums[i + 1] = sum;
        }
        
        int total = 0;
        for(int i = 0; i < sums.size(); i++)
        {
            for(int j = i + 1; j < sums.size(); j++)
            {
                if(sums[j] - sums[i] == k)
                    total++;
            }
        }
        return total;
    }
};