class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return 0;
        vector<int> v(26,0);
        vector<int> x;
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'a']++;
            if(s[i]!=goal[i])
                x.push_back(i);
        }
        if(x.size()==2)
        {
            swap(s[x[0]],s[x[1]]);
            if(s==goal)
                return 1;
            return 0;
        }
        else if(x.size()==0)
        {
            for(auto i:v)
            {
                if(i>1)
                    return 1;
            }
        }
        return 0;
    }
};