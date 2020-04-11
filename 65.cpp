class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            colors[nums[i]]++;
        }
        int currentLoc = 0;
        for(int i = currentLoc; i < colors[0]; i++)
        {
            nums[i] = 0;
        }
        currentLoc += colors[0];
        for(int i = currentLoc; i < currentLoc + colors[1]; i++)
        {
            nums[i] = 1;
        }
        currentLoc += colors[1];
        for(int i = currentLoc; i < currentLoc + colors[2]; i++)
        {
            nums[i] = 2;
        }
    }
};