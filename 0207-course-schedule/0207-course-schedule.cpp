class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> v(n);
        vector<int> f(n,0);
        for(auto i:p)
        {
            v[i[1]].push_back(i[0]);
            f[i[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(f[i]==0)
                q.push(i);
        }
        int c=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            c++;
            for(auto i:v[x])
            {
                f[i]--;
                if(f[i]==0)
                    q.push(i);
            }
        }
        return c==n;
    }
};