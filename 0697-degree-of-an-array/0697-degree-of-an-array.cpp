class Solution {
public:
    int findShortestSubArray(vector<int>& v) {
        map<int,vector<int>> m;
        int maxi=0;
        for(int i=0;i<v.size();i++)
        {
            m[v[i]].push_back(i);
            maxi=max(maxi,(int)m[v[i]].size());
        }
        int mini=INT_MAX;
        for(auto i:m)
        {
            if(i.second.size()!=maxi)
                continue;
            mini=min(mini,i.second.back()-i.second[0]+1);
        }
        return mini;
    }
};