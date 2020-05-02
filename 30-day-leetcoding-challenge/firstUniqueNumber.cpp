class FirstUnique {
public:
    unordered_set<int> uniques;
    unordered_set<int> toRemove;
    queue<int> seenOrder;
    
    FirstUnique(vector<int>& nums) {
        for(auto elem : nums)
        {
            add(elem);
        }
    }
    
    int showFirstUnique() {
        if(seenOrder.size() != 0)
        {
            return seenOrder.front();
        }
        else
        {
            return -1;
        }
    }
    
    void add(int value) {
        auto itr = uniques.find(value);
        if (itr == uniques.end())
        {
            seenOrder.push(value);
            uniques.insert(value);
        }
        else
        {
            toRemove.insert(value);
            while(seenOrder.size() && toRemove.find(seenOrder.front()) != toRemove.end())
            {
                seenOrder.pop();
            }
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */