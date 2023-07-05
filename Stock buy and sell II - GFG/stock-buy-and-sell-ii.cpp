//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int cal(int n,vector<int>& v,int i,int c,vector<vector<int>>& dp)
    {
        if(i==n)
            return 0;
        if(dp[i][c]!=-1)
            return dp[i][c];
        if(c==0)
        {
            return dp[i][c]=max(-v[i]+cal(n,v,i+1,1,dp),cal(n,v,i+1,0,dp));
        }
        else
            return dp[i][c]=max(v[i]+cal(n,v,i,0,dp),cal(n,v,i+1,1,dp));
    }
    int stockBuyAndSell(int n, vector<int> &v) {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            dp[i][0]=max(-v[i]+dp[i+1][1],dp[i+1][0]);
            dp[i][1]=max(v[i]+dp[i][0],dp[i+1][1]);
        }
        return dp[0][0];
        //return cal(n,prices,0,0,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends