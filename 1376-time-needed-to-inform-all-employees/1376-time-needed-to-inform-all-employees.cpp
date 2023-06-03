class Solution {
public:
    int cal(int x,vector<vector<int>>& v,vector<int>& t)
    {
        int ans=(v[x].size()?t[x]:0);
        int maxi=0;
        for(auto i:v[x])
        {
            maxi=max(maxi,cal(i,v,t));
        }
        return ans+maxi;
    }
    int numOfMinutes(int n, int x, vector<int>& manager, vector<int>& t) {
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]==-1)
                continue;
            v[manager[i]].push_back(i);
        }
        return cal(x,v,t);
    }
};