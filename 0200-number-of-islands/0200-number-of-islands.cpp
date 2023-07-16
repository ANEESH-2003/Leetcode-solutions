class Solution {
public:
    int numIslands(vector<vector<char>>& v) {
        int n=v.size();
        int m=v[0].size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]!='1')
                    continue;
                else
                {
                    c++;
                    queue<vector<int>> q;
                    q.push({i,j});
                    v[i][j]='2';
                    while(!q.empty())
                    {
                        int s=q.size();
                        while(s--)
                        {
                            vector<int> f=q.front();
                            int x=f[0],y=f[1];
                            q.pop();
                            if(x-1>=0 && x-1<n && y>=0 && y<m && v[x-1][y]=='1')
                            {
                                q.push({x-1,y});
                                v[x-1][y]='2';
                            }
                            if(x>=0 && x<n && y-1>=0 && y-1<m && v[x][y-1]=='1')
                            {
                                q.push({x,y-1});
                                v[x][y-1]='2';
                            }
                            if(x+1>=0 && x+1<n && y>=0 && y<m && v[x+1][y]=='1')
                            {
                                q.push({x+1,y});
                                v[x+1][y]='2';
                            }
                            if(x>=0 && x<n && y+1>=0 && y+1<m && v[x][y+1]=='1')
                            {
                                q.push({x,y+1});
                                v[x][y+1]='2';
                            }
                        }
                    }
                }
            }
        }
        return c;
    }
};