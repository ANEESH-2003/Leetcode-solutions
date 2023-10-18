class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& t) {
        vector<vector<int>> v(n+1);
        vector<int> f(n+1,0);
        for(auto i:r)
        {
            v[i[0]].push_back(i[1]);
            f[i[1]]++;
        }
        int c=0;
        queue<pair<int,int>> q;
        for(int i=1;i<=n;i++)
        {
            if(f[i]==0)
            {
                q.push({i,0});
                c=max(c,t[i-1]);
            }
        }
        vector<int> m(n+1,0);
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(auto i:v[p.first])
                {
                    f[i]--;
                    m[i]=max(m[i],p.second+t[p.first-1]);
                    if(!f[i])
                    {
                        q.push({i,m[i]});
                        c=max(c,m[i]+t[i-1]);
                    }
                }
            }
        }
        return c;
    }
};