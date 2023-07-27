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
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=cal(coins,0,amount,dp);
        return ans>1e4?-1:ans;
    }
};