class Solution {
public:
    vector<int> xorQueries(vector<int>& v, vector<vector<int>>& q) {
        for(int i=1;i<v.size();i++)
        {
            v[i]=v[i]^v[i-1];
        }
        vector<int> ans;
        for(int i=0;i<q.size();i++)
        {
            int x=v[q[i][1]];
            if(q[i][0]!=0)
                x=x^v[q[i][0]-1];
            ans.push_back(x);
        }
        return ans;
    }
};