class Solution {
public:
    bool poss=true;
    map<int,int> cal(int k,vector<vector<int>>& v)
    {
        map<int,vector<int>> m;
        map<int,int> f;
        map<int,int> ans;
        for(auto i:v)
        {
            int x=i[0],y=i[1];
            m[x].push_back(y);
            f[y]++;
        }
        int c=0;
        while(c<k)
        {
            int x=c;
            for(int i=1;i<=k;i++)
            {
                if(f[i]==0)
                {
                    f[i]=-1;
                    ans[i]=c;
                    for(auto j:m[i])
                        f[j]--;
                    c++;
                    break;
                }
            }
            if(x==c)
            {
                poss=0;
                return ans;
            }
        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        map<int,int> rs=cal(k,r);
        map<int,int> cs=cal(k,c);
        vector<vector<int>> ans;
        if(!poss)
            return ans;
        ans.resize(k,vector<int>(k,0));
        for(int i=1;i<=k;i++)
        {
            ans[rs[i]][cs[i]]=i;
        }
        return ans;
    }
};