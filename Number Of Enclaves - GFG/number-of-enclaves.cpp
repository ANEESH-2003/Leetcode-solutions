//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool val(int x,int y,int& n,int& m,vector<vector<int>>& v)
  {
      return (x>=0 && y>=0 && x<n && y<m && v[x][y]);
  }
    int numberOfEnclaves(vector<vector<int>> &v) {
        // Code here
        queue<pair<int,int>> q;
        int n=v.size();
        int m=v[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[i][0])
            {
                q.push({i,0});
                ans++;
                v[i][0]=0;
            }
            if(v[i][m-1])
            {
                q.push({i,m-1});
                v[i][m-1]=0;
                ans++;
            }
        }
        for(int i=1;i<m-1;i++)
        {
            if(v[0][i])
            {
                q.push({0,i});
                v[0][i]=0;
                ans++;
            }
            if(v[n-1][i])
            {
                q.push({n-1,i});
                v[n-1][i]=0;
                ans++;
            }
        }
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                pair<int,int> p=q.front();
                q.pop();
                int x=p.first,y=p.second;
                if(val(x-1,y,n,m,v))
                {
                    q.push({x-1,y});
                    v[x-1][y]=0;
                    ans++;
                }
                if(val(x+1,y,n,m,v))
                {
                    q.push({x+1,y});
                    v[x+1][y]=0;
                    ans++;
                }
                if(val(x,y-1,n,m,v))
                {
                    q.push({x,y-1});
                    v[x][y-1]=0;
                    ans++;
                }
                if(val(x,y+1,n,m,v))
                {
                    q.push({x,y+1});
                    v[x][y+1]=0;
                    ans++;
                }
            }
        }
        ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                ans+=v[i][j];
        }
        return abs(ans);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends