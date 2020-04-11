class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        
        string convertedVal = to_string(x);
        string reversedVal = to_string(x);
        reverse(reversedVal.begin(), reversedVal.end());
        return convertedVal == reversedVal;
    }
};