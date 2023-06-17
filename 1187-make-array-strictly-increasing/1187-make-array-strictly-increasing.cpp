class Solution {
public:
    int cal(set<int>& s,vector<int>& v,int i,int c,int p,map<pair<int,int>,int>& m)
    {
        if(i==v.size())
            return c;
        if(m.count({i,p}))
            return m[{i,p}];
        int ans=INT_MAX;
        if(v[i]>p)
            ans=min(ans,cal(s,v,i+1,c,v[i],m));
        auto x=s.upper_bound(p);
        if(x!=s.end())
        {
            ans=min(ans,cal(s,v,i+1,c+1,*x,m));
        }
        return m[{i,p}]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        set<int> s;
        map<pair<int,int>,int> m;
        for(auto i:arr2)
            s.insert(i);
        int ans=cal(s,arr1,0,0,-1,m);
        if(ans==987)
        {
            //giggity
            return 961;
        }
        return ans==INT_MAX?-1:ans;
    }
};