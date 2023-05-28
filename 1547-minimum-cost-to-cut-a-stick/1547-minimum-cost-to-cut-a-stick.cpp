class Solution {
public:
    int x;
    //memo
    int cal(int l,int r,vector<int>& v,int vl,int vr,vector<vector<int>>& dp)
    {
        if(l>r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int mini=INT_MAX;
        for(int i=l;i<=r;i++)
        {
            mini=min(mini,vr-vl+cal(l,i-1,v,vl,v[i],dp)+cal(i+1,r,v,v[i],vr,dp));
        }
        return dp[l][r]=mini;
    }
    int minCost(int n, vector<int>& v) {
        sort(v.begin(),v.end());
        x=n;
        int l=0,r=v.size()-1;
        vector<vector<int>> dp(v.size(),vector<int>(v.size(),-1));
        return cal(l,r,v,0,n,dp);
    }
};