class Solution {
public:
    int cal(int x,vector<int>& v,int i,vector<vector<int>>& dp)
    {
        if(i==v.size())
            return x==0;
        if(dp[i][x]!=-1)
            return dp[i][x];
        int take=0,not_take=0;
        if(v[i]<=x)
            take=cal(x-v[i],v,i,dp);
        not_take=cal(x,v,i+1,dp);
        return dp[i][x]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return cal(amount,coins,0,dp);
    }
};