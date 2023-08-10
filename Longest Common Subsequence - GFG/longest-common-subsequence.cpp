//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int cal(int i,int j,int& n,int& m,string& a,string& b,vector<vector<int>>& dp)
    {
        if(i==n || j==m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take=0,not_take=0;
        if(a[i]==b[j])
            take=1+cal(i+1,j+1,n,m,a,b,dp);
        not_take=max(cal(i+1,j,n,m,a,b,dp),cal(i,j+1,n,m,a,b,dp));
        return dp[i][j]=max(take,not_take);
    }
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<int> c(m+1,0),p(m+1,0);
        for(int i=1;i<=n;i++)
        {
            c[0]=0;
            for(int j=1;j<=m;j++)
            {
                c[j]=0;
                if(s1[i-1]==s2[j-1])
                    c[j]=1+p[j-1];
                c[j]=max(c[j],max(p[j],c[j-1]));
            }
            p=c;
        }
        return c[m];
        //return cal(0,0,n,m,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends