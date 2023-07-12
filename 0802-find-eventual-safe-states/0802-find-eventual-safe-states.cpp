class Solution {
public:
    int cal(vector<int>& vis,vector<vector<int>>& v,vector<int>& ans,int x)
    {
        if(vis[x])
            return -1;
        if(ans[x])
            return ans[x];
        vis[x]++;
        int f=INT_MAX;
        for(auto i:v[x])
        {
            f=min(f,cal(vis,v,ans,i));
        }
        vis[x]--;
        return ans[x]=f==INT_MAX?1:f;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(!ans[i])
            {
                vector<int> vis(n,0);
                ans[i]=cal(vis,v,ans,i);
            }
        }
        vector<int> ret;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==1)
                ret.push_back(i);
        }
        return ret;
    }
};