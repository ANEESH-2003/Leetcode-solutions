//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int cal(int i,int& n,vector<vector<bool>>& dp,vector<int>& v)
    {
        if(i==n)
            return 0;
        if(v[i]!=-1)
            return v[i];
        int ans=520;
        for(int j=i;j<n;j++)
        {
            if(dp[i][j])
                ans=min(ans,1+cal(j+1,n,dp,v));
        }
        return v[i]=ans;
    }
    int palindromicPartition(string s)
    {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]!=s[j])
                    continue;
                else
                {
                    if(i+1>j-1)
                        dp[i][j]=1;
                    else
                        dp[i][j]=dp[i+1][j-1];
                }
            }
        }
        vector<int> ans(n,-1);
        return cal(0,n,dp,ans)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends