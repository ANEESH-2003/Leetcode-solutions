class Solution {
public:
    bool cal(string& a,string& b,string& c,int i,int j,vector<vector<int>>& v)
    {
        if(i==a.size() && j==b.size())
            return 1;
        if(v[i][j]!=-1)
            return v[i][j];
        bool ans=0;
        if(i<a.size() && a[i]==c[i+j])
            ans=ans|cal(a,b,c,i+1,j,v);
        if(j<b.size() && b[j]==c[i+j])
            ans=ans|cal(a,b,c,i,j+1,v);
        return v[i][j]=ans;
    }
    bool isInterleave(string a, string b, string c) {
        if(a.size()+b.size()!=c.size())
            return 0;
        vector<vector<int>> v(a.size()+1,vector<int>(b.size()+1,-1));
        return cal(a,b,c,0,0,v);
    }
};