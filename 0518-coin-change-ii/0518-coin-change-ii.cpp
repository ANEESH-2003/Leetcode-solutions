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
        vector<int> p(amount+1,0),c(amount+1,0);
        int n=coins.size();
        for(int i=1;i<=coins.size();i++)
        {
            c[0]=1;
            for(int j=1;j<=amount;j++)
            {
                int take=0,not_take=0;
                if(coins[i-1]<=j)
                    take=c[j-coins[i-1]];
                not_take=p[j];
                c[j]=take+not_take;
            }
            p=c;
        }
        return c[amount];
        //return cal(amount,coins,0,dp);
    }
};