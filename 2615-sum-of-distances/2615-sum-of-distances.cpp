class Solution {
public:
    vector<long long> distance(vector<int>& v) {
        map<int,long long> p,c;
        vector<long long> ans(v.size(),0);
        for(int i=0;i<v.size();i++)
        {
            ans[i]+=c[v[i]]*i-p[v[i]];
            p[v[i]]+=i;
            c[v[i]]++;
        }
        map<int,long long> mp,mc;
        for(int i=v.size()-1;i>=0;i--)
        {
            ans[i]+=mp[v[i]]-mc[v[i]]*i;
            mp[v[i]]+=i;
            mc[v[i]]++;
        }
        return ans;
    }
};