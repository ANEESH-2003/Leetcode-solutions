class Solution {
public:
    int n;
    int cal(vector<int>& v,int i,int c,vector<int>& dp)
    {
        if(i==n)
            return 0;
        if(dp[i]!=-1 && c==0)
            return dp[i];
        int maxi=INT_MIN;
        if(c)
            maxi=INT_MAX;
        int s=0;
        for(int j=0;i+j<n && j<=2;j++)
        {
            s+=v[i+j];
            int a=cal(v,i+j+1,1-c,dp);
            if(c==0)
                maxi=max(maxi,s+a);
            else
                maxi=min(maxi,a);
        }
        if(c==0)
            dp[i]=maxi;
        return maxi;
    }
    string stoneGameIII(vector<int>& v) {
        n=v.size();
        int s=accumulate(v.begin(),v.end(),0);
        vector<int> dp(n,-1);
        int c=cal(v,0,0,dp);
        if(s-c<c)
            return "Alice";
        else if(s-c>c)
            return "Bob";
        else
            return "Tie";
    }
};