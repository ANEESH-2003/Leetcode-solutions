class Solution {
public:
    int n;
    void cal(vector<vector<int>>& ret,vector<int>& ans,vector<int>& v,int t,int i)
    {
        if(t==0)
        {
            ret.push_back(ans);
            return;
        }
        if(i==n)
            return;
        cal(ret,ans,v,t,i+1);
        if(v[i]<=t)
        {
            ans.push_back(v[i]);
            cal(ret,ans,v,t-v[i],i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        n=v.size();
        sort(v.begin(),v.end());
        vector<int> ans;
        vector<vector<int>> ret;
        cal(ret,ans,v,t,0);
        return ret;
    }
};