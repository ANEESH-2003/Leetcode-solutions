class Solution {
public:
    int cal(vector<int>& coins,int i,int amount,vector<vector<int>>& dp)
    {
        if(i==coins.size())
            return amount==0?0:1e4+1;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int take=1e4+1,not_take=1e4+1;
        if(coins[i]<=amount)
            take=1+cal(coins,i,amount-coins[i],dp);
        not_take=cal(coins,i+1,amount,dp);
        return dp[i][amount]=min(take,not_take);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        int n=coins.size();
        for(int i=0;i<n;i++)
        {
            if(amount>=coins[i])
            dp[i][coins[i]]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                int take=1e4+1,not_take=1e4+1;
                if(coins[i]<=j)
                    take=1+dp[i][j-coins[i]];
                if(i)
                    not_take=dp[i-1][j];
                dp[i][j]=min(take,not_take);
            }
        }
        return dp[n-1][amount]>1e4?-1:dp[n-1][amount];
        //return ans>1e4?-1:ans;
    }
};