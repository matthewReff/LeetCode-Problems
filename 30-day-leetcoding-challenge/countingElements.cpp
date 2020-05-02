class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int> vals;
        for(int i = 0; i < arr.size(); i++)
        {
            vals[arr[i]]++;
        }
        
        auto current = vals.begin();
        auto next = current;
        next++;
        
        int total = 0;
        while(next != vals.end())
        {
            if(current->first + 1 == next->first)
            {
                total += current->second;
            }
            current = next;
            next++;
        }
        
        return total;
    }
};