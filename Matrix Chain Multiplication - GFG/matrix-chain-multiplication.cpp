//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int cal(int v[],int& n,int i,int j,vector<vector<int>>& dp)
    {
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=1e9;
        for(int k=i;k<j;k++)
        {
            int x=v[i-1]*v[k]*v[j]+cal(v,n,k+1,j,dp)+cal(v,n,i,k,dp);
            ans=min(ans,x);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int n, int v[])
    {
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return cal(v,n,1,n-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends