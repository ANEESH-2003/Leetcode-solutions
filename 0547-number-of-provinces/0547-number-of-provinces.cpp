class Solution {
public:
    int n;
    void cal(vector<int>& vis,vector<vector<int>>& v,int i)
    {
        vis[i]++;
        for(int j=0;j<n;j++)
        {
            if(v[i][j] && !vis[j])
            {
                cal(vis,v,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        n=v.size();
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i])
                continue;
            ans++;
            cal(vis,v,i);
        }
        return ans;
    }
};