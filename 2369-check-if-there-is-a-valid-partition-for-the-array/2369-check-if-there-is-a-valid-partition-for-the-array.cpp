class Solution {
public:
    bool cal(int i,vector<int>& v,vector<int>& dp)
    {
        if(i==v.size())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        bool ans=0;
        if(i+1<v.size())
        {
            if(v[i]==v[i+1])
                ans|=cal(i+2,v,dp);
        }
        if(i+2<v.size())
        {
            if((v[i]==v[i+1] && v[i]==v[i+2]) || (v[i]+1==v[i+1] && v[i]+2==v[i+2]))
                ans|=cal(i+3,v,dp);
        }
        return dp[i]=ans;
    }
    bool validPartition(vector<int>& v) {
        vector<bool> dp(v.size()+1,0);
        int n=v.size();
        dp[n]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(i+1<n)
            {
                if(v[i]==v[i+1])
                    dp[i]=dp[i]|dp[i+2];
            }
            if(i+2<n)
            {
                if((v[i]==v[i+1] && v[i]==v[i+2]) || (v[i]+1==v[i+1] && v[i]+2==v[i+2]))
                    dp[i]=dp[i]|dp[i+3];
            }
        }
        return dp[0];
        //return cal(0,v,dp);
    }
};