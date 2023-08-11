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
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        int n=coins.size();
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                int take=0,not_take=0;
                if(coins[i-1]<=j)
                    take=dp[i][j-coins[i-1]];
                not_take=dp[i-1][j];
                dp[i][j]=take+not_take;
            }
        }
        return dp[coins.size()][amount];
        return cal(amount,coins,0,dp);
    }
};