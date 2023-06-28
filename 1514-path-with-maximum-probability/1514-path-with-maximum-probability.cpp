class Solution {
public:
    double ans;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& s, int a, int b) {
        vector<double> vis(n,0);
        vector<vector<pair<int,double>>> v(n);
        for(int i=0;i<edges.size();i++)
        {
            v[edges[i][0]].push_back({edges[i][1],s[i]});
            v[edges[i][1]].push_back({edges[i][0],s[i]});
        }
        priority_queue<pair<double,int>> p;
        p.push({0,a});
        vis[a]=1;
        while(!p.empty())
        {
            pair<double,int> x=p.top();
            p.pop();
            for(auto i:v[x.second])
            {
                if(vis[i.first]<vis[x.second]*i.second)
                {
                    vis[i.first]=vis[x.second]*i.second;
                    p.push({vis[i.first],i.first});
                }
            }
        }
        return vis[b];
    }
};