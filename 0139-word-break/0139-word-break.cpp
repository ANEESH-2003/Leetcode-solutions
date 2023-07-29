class Solution {
public:
    int n;
    bool cal(int i,string& s,set<string>& st,vector<int>& v)
    {
        if(i==n)
            return 1;
        if(v[i]!=-1)
            return v[i];
        string x="";
        bool ans=0;
        for(int j=i;j<=min(n-1,i+19);j++)
        {
            x+=s[j];
            if(st.find(x)!=st.end())
            {
                ans|=cal(j+1,s,st,v);
            }
        }
        return v[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        set<string> st;
        vector<int> v(n,-1);
        for(auto i:wordDict)
            st.insert(i);
        return cal(0,s,st,v);
    }
};