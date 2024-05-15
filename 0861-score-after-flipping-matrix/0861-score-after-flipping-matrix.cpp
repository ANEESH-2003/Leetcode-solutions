class Solution {
public:
int score(vector<int>v)
{
    int sc=0,c=0;
    for(int i=v.size()-1;i>=0;i--){
    sc=sc+v[i]*pow(2,c);
    c++;
    }
    return sc;
}

    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;
            }

        }
      
        for(int j=0;j<grid[0].size();j++)
        {    int czero=0;
            for(int i=0;i<grid.size();i++)
            {
               if(grid[i][j]==0) czero++;

            }
            if(czero>grid.size()/2)
            {
                for(int i=0;i<grid.size();i++)
                {
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }

        }
        int sc=0;
        for(int i=0;i<grid.size();i++)
        {
            sc+=score(grid[i]);
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                cout<<grid[i][j]<<" ";
            }cout<<endl;
        }
        return sc;
    }
};