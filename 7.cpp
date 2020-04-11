class Solution {
public:
    int reverse(int x) {
        bool isNegative = x < 0;
        x = abs(x);
        long newVal = 0;
        while(x > 0)
        {
            if(newVal > 214748364)
            {
                return 0;
            }
            newVal *= 10;
            newVal += x % 10;
            x /= 10;
        }
        if(isNegative)
        {
            return -newVal;
        }
        else
        {
            return newVal;
        }
    }
};