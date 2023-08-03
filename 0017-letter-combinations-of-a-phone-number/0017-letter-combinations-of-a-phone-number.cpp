class Solution {
public:
    vector<string> v;
    map<char,string> m;
    void cal(string& s,int i,string f)
    {
        if(i==s.size())
        {    
            if(f.size())
                v.push_back(f);
            return ;
        }
        string x;
        for(auto j:m[s[i]])
        {
            x=f;
            x+=j;
            cal(s,i+1,x);
        }
    }
    vector<string> letterCombinations(string digits) {
        m['2']={"abc"};
        m['3']={"def"};
        m['4']={"ghi"};
        m['5']={"jkl"};
        m['6']={"mno"};
        m['7']={"pqrs"};
        m['8']={"tuv"};
        m['9']={"wxyz"};
        cal(digits,0,"");
        return v;
    }
};