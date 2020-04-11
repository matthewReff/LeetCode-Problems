class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int start = 0;
        int end = nums.size() - 1;
        
        if(nums.size() == 1)
        {
            return 0;
        }
        else if(nums[0] > nums[1])
        {
            return 0;
        }
        else if(nums[nums.size()-1] > nums[nums.size() - 2])
        {
            return nums.size() -1;
        }
        
        nums.push_back(9999999);
        
        while(start < end)
        {
            int mid = start + (end - start) / 2; 
            cerr << mid << "\n";
            // If the element is present at the middle 
            // itself 
            if ((nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) || mid == end) 
            {
                return mid; 
            }
            
            // If element is smaller than mid, then 
            // it can only be present in left subarray 
            if (nums[mid] > nums[mid+1]) 
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
            // Else the element can only be present 
            // in right subarray 
        } 
    return start;
    }
};