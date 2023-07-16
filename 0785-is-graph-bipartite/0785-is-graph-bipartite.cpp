class Solution {
public:
    bool cal(vector<int>& v,int i,vector<vector<int>>& graph,int c)
    {
        v[i]=c;
        bool ans=false;
        for(auto j:graph[i])
        {
            if(v[j])
            {
                if(v[j]==c)
                    ans=1;
                continue;
            }
            else
                ans=ans|cal(v,j,graph,3-c);
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
        {
            if(v[i])
                continue;
            else if(cal(v,i,graph,1))
                return 0;
        }
        return 1;
    }
};