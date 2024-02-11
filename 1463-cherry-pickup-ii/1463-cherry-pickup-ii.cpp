class Solution {
public:
    int cal(vector<vector<vector<int>>>& v,int& n,int& m,int x,int y,int i,vector<vector<int>>& g)
    {
        //cout<<i<<" "<<x<<" "<<y<<"\n";
        if(i==n)
            return 0;
        if(x<0 || y<0 || x==m || y==m)
            return 0;
        if(v[x][y][i]!=-1)
            return v[x][y][i];
        int ans=g[i][x]+g[i][y];
        if(x==y)
            ans/=2;
        v[x][y][i]=0;
        for(int j=-1;j<=1;j++)
        {
            for(int k=-1;k<=1;k++)
            {
                v[x][y][i]=max(v[x][y][i],cal(v,n,m,x+j,y+k,i+1,g));
            }
        }
        v[x][y][i]+=ans;
        return v[x][y][i];
    }
    int cherryPickup(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<vector<int>>> v(m,vector<vector<int>>(m,vector<int>(n,-1)));
        return cal(v,n,m,0,m-1,0,g);
    }
};