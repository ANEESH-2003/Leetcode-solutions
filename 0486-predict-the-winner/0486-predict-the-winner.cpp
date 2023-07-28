class Solution {
public:
    int cal(vector<int>& nums,int l,int r,int p,vector<vector<int>>& dp)
    {
        if(l>r)
            return 0;
        if(dp[l][r]!=1e9)
            return dp[l][r];
        int first=p*nums[l]+cal(nums,l+1,r,-p,dp);
        int last=p*nums[r]+cal(nums,l,r-1,-p,dp);
        return dp[l][r]=p==-1?min(first,last):max(first,last);
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            dp[i][i]=(n%2?1:-1)*nums[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int p=(n-1-j+i+1)%2?1:-1;
                int first=p*nums[i]+dp[i+1][j];
                int last=p*nums[j]+dp[i][j-1];
                dp[i][j]=p==-1?min(first,last):max(first,last);
            }
        }
        return dp[0][n-1]>=0;
        return cal(nums,0,nums.size()-1,1,dp)>=0;
    }
};