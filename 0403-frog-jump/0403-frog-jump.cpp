class Solution {
public:
    map<pair<int,int>,bool> ma;
    bool cal(int i,int p,vector<int>& v,int& n,map<int,int>& m)
    {
        if(i==n-1)
            return 1;
        if(ma.find({i,p})!=ma.end())
            return ma[{i,p}];
        bool ans=0;
        if(m.find(v[i]+p-1)!=m.end() && v[i]+p-1!=v[i])
            ans=ans|cal(m[v[i]+p-1],p-1,v,n,m);
        if(m.find(v[i]+p+1)!=m.end() && v[i]+p+1!=v[i])
            ans=ans|cal(m[v[i]+p+1],p+1,v,n,m);
        if(m.find(v[i]+p)!=m.end() && v[i]+p!=v[i])
            ans=ans|cal(m[v[i]+p],p,v,n,m);
        return ma[{i,p}]=ans;
    }
    bool canCross(vector<int>& v) {
        int n=v.size();
        map<int,int> m;
        for(int i=0;i<n;i++)
            m[v[i]]=i;
        if(m.find(1)==m.end())
            return 0;
        return cal(m[1],1,v,n,m);
    }
};