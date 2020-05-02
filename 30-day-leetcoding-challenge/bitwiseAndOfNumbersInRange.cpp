class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        if (m == 0 || n == 0)
        {
            return 0;
        }

        int length = max(ceil(log2((long)m+1)), ceil(log2((long)n+1)));                      
        vector<bool> mArr(length, false);
        vector<bool> nArr(length, false);
        long answer = 0;

        for (int i = length - 1; i >= 0; i--)
        {
            if ((m >> (length - 1 - i) & 1))
                mArr[i] = true;
            if ((n >> (length - 1 - i)) & 1)
                nArr[i] = true;
        }

        int firstDiff = length;
        for (int i = 0; i < length; i++)
        {
            if (mArr[i] != nArr[i])
            {
                firstDiff = i;
                break;
            }
        }

        for (int i = 0; i < firstDiff; i++)
        {
            if (mArr[i])
            {
                int orVal = (1 << (length - i - 1));
                answer |= orVal;
            }
        }
        return (int)answer;
    }
};