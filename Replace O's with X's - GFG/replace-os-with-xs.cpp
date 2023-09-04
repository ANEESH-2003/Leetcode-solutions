//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isval(int n,int m,int x,int y)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> v)
    {
        queue<vector<int>> q;
        for(int i=0;i<n;i++)
        {
            if(v[i][0]=='O')
            {
                q.push({i,0});
                v[i][0]='$';
            }
            if(v[i][m-1]=='O')
            {
                q.push({i,m-1});
                v[i][m-1]='$';
            }
        }
        for(int i=1;i<m-1;i++)
        {
            if(v[0][i]=='O')
            {
                q.push({0,i});
                v[0][i]='$';
            }
            if(v[n-1][i]=='O')
            {
                q.push({n-1,i});
                v[n-1][i]='$';
            }
        }
        while(!q.empty())
        {
            int l=q.size();
            while(l--)
            {
                vector<int> f=q.front();
                int x=f[0],y=f[1];
                q.pop();
                if(isval(n,m,x-1,y) && v[x-1][y]=='O')
                {
                    v[x-1][y]='$';
                    q.push({x-1,y});
                }
                if(isval(n,m,x+1,y) && v[x+1][y]=='O')
                {
                    v[x+1][y]='$';
                    q.push({x+1,y});
                }
                if(isval(n,m,x,y-1) && v[x][y-1]=='O')
                {
                    v[x][y-1]='$';
                    q.push({x,y-1});
                }
                if(isval(n,m,x,y+1) && v[x][y+1]=='O')
                {
                    v[x][y+1]='$';
                    q.push({x,y+1});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='$')
                    v[i][j]='O';
                else
                    v[i][j]='X';
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends