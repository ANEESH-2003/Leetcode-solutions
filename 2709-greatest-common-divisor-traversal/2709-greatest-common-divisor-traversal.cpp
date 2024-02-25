class Solution {
public:
    int n;
    int find_set(vector<int>& p,int v) 
    {
        if(v==p[v])
            return v;
        return p[v]=find_set(p,p[v]);
    }
    void uni(vector<int>& p,int a,int b,vector<int>& r)
    {
        a=find_set(p,a);
        b=find_set(p,b);
        if (a != b) 
        {
            if(r[a]<r[b])
                swap(a,b);
            p[b]=a;
            if(r[a]==r[b])
                r[a]++;
        }
    }
    bool canTraverseAllPairs(vector<int>& v) {
        n=v.size();
        vector<int> p(n);
        vector<int> r(n,0);
        for(int i=0;i<n;i++)
            p[i]=i;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++)
        {
            for(int j=2;j*j<=v[i];j++)
            {
                if(v[i]%j==0)
                {
                    m[j].push_back(i);
                    while(v[i]%j==0)
                    {
                        v[i]/=j;
                    }
                }
            }
            if(v[i]>1)
            {
                m[v[i]].push_back(i);
            }
        }
        for(auto i:m)
        {
            for(int j=1;j<i.second.size();j++)
            {
                uni(p,i.second[j-1],i.second[j],r);
            }
        }
        int he=find_set(p,0);
        for(int i=1;i<n;i++)
        {
            if(find_set(p,i)!=he)
                return 0;
        }
        return 1;
    }
};