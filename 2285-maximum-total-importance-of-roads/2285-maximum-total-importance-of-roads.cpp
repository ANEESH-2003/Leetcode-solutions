class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> v(n,0);
        for(auto i:roads)
        {
            v[i[0]]++;
            v[i[1]]++;
        }
        sort(v.begin(),v.end());
        long long ans=0;
        int x=1;
        for(auto i:v)
        {
            ans+=(long long)i*(long long)x++;
        }
        return ans;
    }
};