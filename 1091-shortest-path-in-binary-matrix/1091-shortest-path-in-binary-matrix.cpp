class Solution {
public:
    int n;
    bool val(int a,int b)
    {
        return (a>=0 && a<n && b>=0 && b<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
        n=v.size();
        if(v[0][0])
            return -1;
        if(n==1)
            return 1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        v[0][0]=1;
        while(!q.empty())
        {
            int l=q.size();
            while(l--)
            {
                pair<int,int> f=q.front();
                q.pop();
                int a=f.first,b=f.second;
                for(int x=a-1;x<=a+1;x++)
                {
                    for(int y=b-1;y<=b+1;y++)
                    {
                        if(val(x,y) && !vis[x][y] && !v[x][y])
                        {
                            vis[x][y]=vis[a][b]+1;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        return (vis[n-1][n-1]?vis[n-1][n-1]+1:-1);
    }
};