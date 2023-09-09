class Solution {
public:
    int n;
    int cal(vector<int>& v,int& t,int i,int tot,vector<vector<int>>& dp)
    {
        if(tot==t)
            return 1;
        if(tot>t)
            return 0;
        if(dp[i][tot]!=-1)
            return dp[i][tot];
        int ans=0;
        for(int j=0;j<n;j++)
            ans+=cal(v,t,j,tot+v[j],dp);
        /*int not_take=cal(v,t,i+1,tot);
        int take=0;
        if(v[i]+tot<=t)
            take=cal(v,t,i,tot+v[i]);*/
        return dp[i][tot]=ans;
    }
    int combinationSum4(vector<int>& v, int t) {
        n=v.size();
        vector<vector<int>> dp(n,vector<int>(t+1,-1));
        return cal(v,t,0,0,dp);
    }
};