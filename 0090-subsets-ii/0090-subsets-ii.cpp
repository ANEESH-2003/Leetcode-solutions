class Solution {
public:
    void cal(vector<int>& v,vector<int>& ans,set<vector<int>>& s,int& n,int i)
    {
        if(i==n)
        {
            s.insert(ans);
            return;
        }
        cal(v,ans,s,n,i+1);
        ans.push_back(v[i]);
        cal(v,ans,s,n,i+1);
        ans.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        set<vector<int>> s;
        sort(v.begin(),v.end());
        vector<int> ans;
        int n=v.size();
        cal(v,ans,s,n,0);
        vector<vector<int>> ret;
        for(auto i:s)
            ret.push_back(i);
        return ret;
    }
};