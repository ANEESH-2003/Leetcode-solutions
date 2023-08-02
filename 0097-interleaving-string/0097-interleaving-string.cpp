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
        vector<vector<bool>> v(a.size()+1,vector<bool>(b.size()+1,0));
        for(int i=0;i<=a.size();i++)
        {
            for(int j=0;j<=b.size();j++)
            {
                if(i==0 && j==0)
                {
                    v[i][j]=true;
                }
                else if(i==0)
                {
                    if(b[j-1]==c[i+j-1])
                        v[i][j]=v[i][j]||v[i][j-1];
                }
                else if(j==0)
                {
                    if(a[i-1]==c[i+j-1])
                        v[i][j]=v[i][j]||v[i-1][j];
                }
                else
                {
                    if(a[i-1]==c[i+j-1])
                        v[i][j]=v[i][j]||v[i-1][j];
                    if(b[j-1]==c[i+j-1])
                        v[i][j]=v[i][j]||v[i][j-1];
                }
            }
        }
        return v[a.size()][b.size()];
        //return cal(a,b,c,0,0,v);
    }
};