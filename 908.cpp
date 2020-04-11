class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minVal = 10001;
        int maxVal = -1;
        
        for(auto elem : A)
        {
            if(elem < minVal)
            {
                minVal = elem;
            }
            if(elem > maxVal)
            {
                maxVal = elem;
            }
        }
        return max(0, (maxVal - K) - (minVal + K) );
    }
};