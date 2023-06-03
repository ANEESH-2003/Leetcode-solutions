class Solution {
public:
    int n;
    void cal(vector<int>& x,vector<vector<int>>& ans,vector<int>& vis,vector<int>& v,int i)
    {
        if(x.size()==n)
        {
            ans.push_back(x);
            return;
        }
        if(i!=-1)
            vis[i]++;
        for(int j=0;j<n;j++)
        {
            if(vis[j])
                continue;
            x.push_back(v[j]);
            cal(x,ans,vis,v,j);
            x.pop_back();
        }
        if(i!=-1)
            vis[i]--;
    }
    vector<vector<int>> permute(vector<int>& v) {
        n=v.size();
        vector<int> vis(n,0);
        vector<vector<int>> ans;
        vector<int> x;
        cal(x,ans,vis,v,-1);
        return ans;
    }
};