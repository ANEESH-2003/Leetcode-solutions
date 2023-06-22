class Solution {
public:
    bool isopen(char a)
    {
        return (a=='{' || a=='(' || a=='[');
    }
    char closes(char a)
    {
        return (a=='}'?'{':(a==')'?'(':'['));
    }
    bool isValid(string s) {
        stack<char> a;
        for(auto i:s)
        {
            if(isopen(i))
            {
                a.push(i);
            }
            else
            {
                if(!a.empty() && a.top()==closes(i))
                {
                    a.pop();
                }
                else
                    return 0;
            }
        }
        return a.empty();
    }
};