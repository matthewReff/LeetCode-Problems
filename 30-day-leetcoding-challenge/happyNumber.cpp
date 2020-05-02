class Solution {
public:
    int getVal(int current)
    {
        int total = 0;
        do
        {
            total += current % 10;
            current /= 10;
        }while(current > 10);
        return total;
    }
    bool isHappy(int n) {
        set<int> loopFinder;        
        while(loopFinder.find(n) == loopFinder.end())
        {
            loopFinder.insert(n);
            cerr << n << "\n";
            n = getVal(n);
        }
        return n == 1;
    }
};