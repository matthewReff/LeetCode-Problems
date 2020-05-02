class Solution {
public:
    bool checkValidString(string s) {
        stack<int> parenLocs;
        int balance = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                balance++;
            }
            else if(s[i] == ')')
            {
                balance--;
                if(balance < 0)
                {
                    if (parenLocs.size() == 0)
                    {
                        return false;
                    }
                    else
                    {
                        int top = parenLocs.top();
                        parenLocs.pop();
                        s[top] = '(';
                        balance++;
                    }
                }
                    
            }
            else
            {
                parenLocs.push(i);
            }
        }
        
        balance = 0;
        parenLocs = stack<int>();
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ')')
            {
                balance--;
            }
            else if(s[i] == '(')
            {
                balance++;
                if(balance > 0)
                {
                    if(parenLocs.size() == 0)
                    {
                        return false;
                    }
                    else
                    {
                        int top = parenLocs.top();
                        parenLocs.pop();
                        s[top] = ')';
                        balance--;
                    }
                }
            }
            else
            {
                parenLocs.push(i);
            }
        }
        
        return true;
    }
};