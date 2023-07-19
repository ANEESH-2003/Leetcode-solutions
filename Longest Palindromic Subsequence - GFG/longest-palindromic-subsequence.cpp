//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int cal(string& a,string& b)
  {
          int n=a.size();
          vector<vector<int>> v(n+1,vector<int>(n+1,0));
          for(int i=1;i<=n;i++)
            v[i][i]=1;
          for(int i=1;i<=n;i++)
          {
              for(int j=1;j<=n;j++)
              {
                  if(a[i-1]==b[j-1])
                    v[i][j]=1+v[i-1][j-1];
                  else
                    v[i][j]=max({v[i][j-1],v[i-1][j],v[i-1][j-1]});
              }
          }
          return v[n][n];
  }
    int longestPalinSubseq(string x) {
        //code here
        string s=x;
        reverse(s.begin(),s.end());
        return cal(s,x);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends