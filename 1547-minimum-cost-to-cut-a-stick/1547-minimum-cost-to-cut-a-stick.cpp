class Solution {
public:
    int cal(int l,int r,vector<int>& v,int ln,int rn,vector<vector<int>>& dp)
    {
       // cout<<l<<" "<<r<<"\n";
        if(l>r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int ans=INT_MAX;
        for(int i=l;i<=r;i++)
        {
            ans=min(ans,rn-ln+cal(l,i-1,v,ln,v[i],dp)+cal(i+1,r,v,v[i],rn,dp));
        }
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& v) {
        sort(v.begin(),v.end());
        int x=v.size();
        vector<vector<int>> dp(x,vector<int>(x,-1));
        return cal(0,x-1,v,0,n,dp);
    }
};