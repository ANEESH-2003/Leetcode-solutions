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
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return cal(a,b,0,0,dp);
    }
};