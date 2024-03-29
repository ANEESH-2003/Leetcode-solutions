class Solution {
public:
    int n,m;
    int cal(string& a,string& b,int i,int j,vector<vector<int>>& dp)
    {
        if(i==n || j==m)
            return (n-i+m-j);
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j]=cal(a,b,i+1,j+1,dp);
        else
            return dp[i][j]=min(1+cal(a,b,i+1,j,dp),min(1+cal(a,b,i,j+1,dp),1+cal(a,b,i+1,j+1,dp)));
    }
    int minDistance(string a, string b) {
        n=a.size();
        m=b.size();
        vector<int> c(m+1,0),p(m+1,0);
        for(int i=0;i<=m;i++)
            p[i]=i;
        for(int i=1;i<=n;i++)
        {
            c[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    c[j]=p[j-1];
                else
                    c[j]=1+min(c[j-1],min(p[j],p[j-1]));
            }
            p=c;
        }
        return p[m];
        
    }
};