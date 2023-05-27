class Solution {
public:
    int n;
    int cal(vector<int>& v,int i,int c,vector<int>& dp)
    {
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int maxi=INT_MIN;
        int s=0;
        for(int j=0;i+j<n && j<=2;j++)
        {
            s+=v[i+j];
            int a=cal(v,i+j+1,1-c,dp);
            maxi=max(maxi,s-a);
        }
        return dp[i]=maxi;    
    }
    string stoneGameIII(vector<int>& v) {
        n=v.size();
        v.push_back(0);
        v.push_back(0);
        vector<int> dp=v;
        dp.push_back(0);
        for(int i=n-1;i>=0;i--)
        {
            int maxi=INT_MIN;
            int s=0;
            for(int j=0;j<=2;j++)
            {
                s+=v[i+j];
                maxi=max(maxi,s-dp[i+j+1]);
            }
            dp[i]=maxi;
        }
        /*int c=cal(v,0,0,dp);*/
        if(0<dp[0])
            return "Alice";
        else if(0>dp[0])
            return "Bob";
        else
            return "Tie";
    }
};