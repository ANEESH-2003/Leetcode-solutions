class Solution {
public:
    int n,m;
    //memo
    int cal(string& a,string& b,int i,int j,vector<vector<int>>& dp)
    {
        if(i==n || j==m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j]=1+cal(a,b,i+1,j+1,dp);
        return dp[i][j]=max(cal(a,b,i,j+1,dp),cal(a,b,i+1,j,dp));
    }
    int longestCommonSubsequence(string a, string b) {
        n=a.size();
        m=b.size();
        vector<int> p(m+1,0),c(m+1,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    c[j]=1+p[j-1];
                else
                    c[j]=max(c[j-1],p[j]);
            }
            p=c;
        }
        return p[m];
        //return cal(a,b,0,0,dp);
    }
};