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
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),1e9));
        return cal(nums,0,nums.size()-1,1,dp)>=0;
    }
};