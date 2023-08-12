class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        dp[n-1][m-1]=1;
        if(v[n-1][m-1]==1 || v[0][0]==1)
            return 0;
        for(int i=m-2;i>=0;i--)
        {
            if(v[n-1][i]==1)
                break;
            dp[n-1][i]+=dp[n-1][i+1];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(v[i][m-1]==1)
                break;
            dp[i][m-1]+=dp[i+1][m-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                if(v[i][j]==1)
                    continue;
                dp[i][j]+=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};