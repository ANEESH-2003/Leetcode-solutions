class Solution {
public:
int helper(vector<int>&piles,vector<vector<int>>&dp, int i, int m)
{
    if(i>=piles.size())
    return 0;
    if(dp[i][m]!=-1)
    return dp[i][m];
    int ans=INT_MIN;
    int tot=0;
    for(int j=0;j<2*m;j++)
    {
        if(i+j<piles.size())
        tot+=piles[i+j];
        ans=max(ans,tot-helper(piles,dp,i+j+1,max(m,j+1)));
        dp[i][m]=ans;
    }
    return dp[i][m];
}
    int stoneGameII(vector<int>& piles) {
        int sum=0;
        int n=piles.size();
        for(auto it:piles)
        {
            sum+=it;
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int x=helper(piles,dp,0,1);
        return (sum+x)/2;
    }
};