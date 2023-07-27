class Solution {
public:
    bool cal(vector<int>& nums,long long t,int i,vector<vector<int>>& dp)
    {
        if(i==nums.size())
            return t==0;
        if(dp[i][t]!=-1)
            return dp[i][t];
        bool take=0,not_take=0;
        if(nums[i]<=t)
            take=cal(nums,t-nums[i],i+1,dp);
        not_take=cal(nums,t,i+1,dp);
        return dp[i][t]=not_take|take;
    }
    bool canPartition(vector<int>& nums) {
        long long t=accumulate(nums.begin(),nums.end(),0LL);
        vector<vector<int>> dp(nums.size(),vector<int>(t/2+1,-1));
        return t%2?0:cal(nums,t/2,0,dp);
    }
};