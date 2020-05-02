class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() == 0)
        {
            return 0;
        }
        int firstLeft;
        for (firstLeft = 0; firstLeft < prices.size() - 1; firstLeft++)
        {
            if (prices[firstLeft] < prices[firstLeft + 1])
            {
                break;
            }
        }
        prices.erase(prices.begin(), prices.begin() + firstLeft);

        int firstRight;
        for (firstRight = prices.size() - 1; firstRight > 0; firstRight--)
        {
            if (prices[firstRight] > prices[firstRight - 1])
            {
                break;
            }
        }

        prices.erase(prices.begin() + firstRight + 1, prices.end());


        vector<int> bestArr(prices.size() + 1, 0);

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            bestArr[i] = bestArr[i + 1];
            for (int j = i + 1; j < prices.size(); j++)
            {
                int newVal = prices[j] - prices[i] + bestArr[j + 1];
                if (newVal > bestArr[i])
                {
                    bestArr[i] = newVal;
                }
            }
        }
        return bestArr[0];
    }
};