class Solution {
public:
    int mod=1e9+7;
    bool isprime(char c)
    {
        return (c=='2'||c=='3'||c=='5'||c=='7')?1:0;
    }
    int cal(string& s,int k,int& l,int i,int& n,vector<vector<int>>& dp)
    {
        if(i==n)
            return k==0?1:0;
        if(k==0 || !isprime(s[i]))
            return 0;
        if(dp[i][k-1]!=-1)
                return dp[i][k-1];
        //cout<<i<<" \n";
        int ans=0;
        for(int j=i+l-1;j<n;j++)
        {
            if(!isprime(s[j]))
                ans=(ans+cal(s,k-1,l,j+1,n,dp))%mod;
        }
        return dp[i][k-1]=ans;
    }
    int beautifulPartitions(string s, int k, int l) {
        int n=s.size();
        vector<vector<int>> dp(s.size(),vector<int>(k,-1));
        return cal(s,k,l,0,n,dp);
    }
};