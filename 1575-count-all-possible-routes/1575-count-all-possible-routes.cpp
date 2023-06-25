class Solution {
public:
    int n;
    int l;
    int x=1e9+7;
    int cal(vector<int>& v,int c,int t,vector<vector<int>>& dp)
    {
        if(t<0)
            return 0;
        if(dp[c][t]!=-1)
            return dp[c][t];
        int ans=0;
        if(c==l)
            ans=1;
        for(int i=0;i<n;i++)
        {
            if(i==c)
                continue;
            ans=(ans+cal(v,i,t-abs(v[i]-v[c]),dp))%x;
        }
        return dp[c][t]=ans;
    }
    int countRoutes(vector<int>& v, int c, int f, int t) {
        l=f;
        n=v.size();
        //vector<bool> vis(n,0);
        vector<vector<int>> dp(n,vector<int>(201,-1));
        return cal(v,c,t,dp);
    }
};