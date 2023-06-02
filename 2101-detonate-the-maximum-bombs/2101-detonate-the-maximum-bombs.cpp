class Solution {
public:
    bool cal(vector<int>& a,vector<int>& b)
    {
        return (pow((a[0]-b[0]),2)+pow((a[1]-b[1]),2)<=pow((a[2]),2));
    }
    int fun(vector<vector<int>>& v,vector<bool>& vis,int i)
    {
        vis[i]=!vis[i];
        int c=1;
        for(auto j:v[i])
        {
            if(vis[j])
                continue;
            c+=fun(v,vis,j);
        }
        return c;
    }
    int maximumDetonation(vector<vector<int>>& b) {
        int n=b.size();
        int maxi=0;
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cal(b[i],b[j]))
                    v[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n,0);
            maxi=max(maxi,fun(v,vis,i));
        }
        return maxi;
    }
};