class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<vector<int>> q;
        q.push({sr,sc});
        int t=image[sr][sc];
        if(t==color)
            return image;
        image[sr][sc]=color;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                vector<int> v=q.front();
                q.pop();
                for(int i=-1;i<=1;i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                        if((i==0 && j==0) || (i!=0 && j!=0))
                            continue;
                        if((v[0]+i>=0 && v[0]+i<image.size() && v[1]+j>=0 && v[1]+j<image[0].size()) && image[v[0]+i][v[1]+j]==t)
                        {
                            image[v[0]+i][v[1]+j]=color;
                            q.push({v[0]+i,v[1]+j});
                        }
                    }
                }
            }
        }
        return image;
    }
};