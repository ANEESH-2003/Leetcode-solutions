class Solution {
public:
    int n,m;
    int maximalSquare(vector<vector<char>>& v) {
        n=v.size();
        m=v[0].size();
        int maxi=0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0) && v[i][j]=='1')
                {
                    dp[i][j]=1;
                }
                else if(v[i][j]=='1')
                    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi*maxi;
    }
};