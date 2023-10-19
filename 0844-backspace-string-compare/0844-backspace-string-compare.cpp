class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string x="";
        for(auto i:s)
        {
            if(i=='#')
            {
                if(x.size())
                    x.pop_back();
            }
            else
                x+=i;
        }
        string f="";
        for(auto i:t)
        {
            if(i=='#')
            {
                if(f.size())
                    f.pop_back();
            }
            else
                f+=i;
        }
        return x==f;
    }
};