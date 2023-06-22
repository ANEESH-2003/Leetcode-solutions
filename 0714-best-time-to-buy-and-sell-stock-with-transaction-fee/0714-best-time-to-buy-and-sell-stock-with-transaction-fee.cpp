class Solution {
public:
    //tabulation
    int cal(vector<int>& v,int x,int i,int c,vector<vector<int>>& dp)
    {
        if(i==v.size())
        {
            return 0;
        }
        if(dp[i][c]!=-1)
            return dp[i][c];
        if(c)
            return dp[i][c]=max(cal(v,x,i+1,c,dp),+v[i]+cal(v,x,i+1,0,dp));
        return dp[i][c]=max(cal(v,x,i+1,c,dp),-v[i]-x+cal(v,x,i+1,1,dp));
    }
    int maxProfit(vector<int>& v, int x) {
        vector<vector<int>> dp(v.size(),vector<int>(2,0));
        int n=v.size();
        dp[n-1][1]=v[n-1];
        for(int i=n-2;i>=0;i--)
        {
            dp[i][0]=max(dp[i+1][0],-v[i]-x+dp[i+1][1]);
            dp[i][1]=max(dp[i+1][1],v[i]+dp[i+1][0]);
        }
        return dp[0][0];
        //return cal(v,x,0,0,dp);
    }
};