class MinStack {
public:
    int minVal = 2147483647;
    vector<pair<int, int>> baseStack;
    
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(x < minVal)
        {
            minVal = x;
        }
        baseStack.push_back(make_pair(x, minVal));
    }
    
    void pop() {
        baseStack.pop_back();
        if(baseStack.size() == 0)
        {
            minVal = 2147483647;
        }
        else
        {
            minVal = baseStack.back().second;
        }
    }
    
    int top() {
        auto top = baseStack.back();
        return top.first;
    }
    
    int getMin() {
        auto top = baseStack.back();
        return top.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */