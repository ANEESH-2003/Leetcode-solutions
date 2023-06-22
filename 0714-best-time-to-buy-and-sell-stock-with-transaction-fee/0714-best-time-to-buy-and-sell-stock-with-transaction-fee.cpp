class Solution {
public:
    //memoization
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
        vector<vector<int>> dp(v.size(),vector<int>(2,-1));
        return cal(v,x,0,0,dp);
    }
};