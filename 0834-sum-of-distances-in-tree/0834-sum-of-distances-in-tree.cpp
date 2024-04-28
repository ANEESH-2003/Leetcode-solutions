class Solution {
public:
    void cal(vector<vector<int>>& v,int x,vector<int>& kido,vector<int>& a,int p)
    {
        for(auto i:v[x])
        {
            if(i==p)
                continue;
            cal(v,i,kido,a,x);
            kido[x]+=kido[i];
            a[x]+=a[i]+kido[i];
        }
        kido[x]++;
    }
    void dfs(vector<vector<int>>& v,int n,vector<int>& kido,vector<int>& a,int x,int p)
    {
        for(auto i:v[x])
        {
            if(i==p)
                continue;
            a[i]=a[x]-kido[i]+n-kido[i];
            dfs(v,n,kido,a,i,x);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        for(auto i:edges)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        vector<int> a(n,0);
        vector<int> kido(n,0);
        cal(v,0,kido,a,-1);
        dfs(v,n,kido,a,0,-1);
        return a;
    }
};