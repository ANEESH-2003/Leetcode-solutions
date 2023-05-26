class Solution {
public:
    int n;
    int cal(vector<int>& v,int l,int r,int c,vector<vector<vector<int>>>& dp)
    {
        if(l>r)
            return 0;
        int maxi=0;
        if(dp[l][r][c]!=-1)
        {
            return dp[l][r][c];
        }
        if(c==0)
        {
            maxi=max(v[r]+cal(v,l,r-1,1,dp),v[l]+cal(v,l+1,r,1,dp));
        }
        else
        {
            maxi=min(cal(v,l,r-1,0,dp),cal(v,l+1,r,0,dp));
        }
        return dp[l][r][c]=maxi;
    }
    bool stoneGame(vector<int>& v) {
        n=v.size();
        int s=accumulate(v.begin(),v.end(),0);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return s/2<cal(v,0,n-1,0,dp);
        
    }
};