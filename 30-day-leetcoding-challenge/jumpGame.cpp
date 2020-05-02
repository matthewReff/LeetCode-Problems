class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return true;
        vector<bool> used(nums.size());

        queue<int> q;
        q.push(0);
        used[0] = true;

        while (q.size())
        {
            int front = q.front();
            q.pop();

            for (int i = front + 1; i < nums.size() && i < front + nums[front] + 1; i++)
            {
                if (!used[i])
                {
                    used[i] = true;
                    // if range completely inside, don't add
                    if(!(front + nums[front] >= i + nums[i]))
                        q.push(i);
                }
            }
        }

        return used[nums.size() - 1];
    }
};