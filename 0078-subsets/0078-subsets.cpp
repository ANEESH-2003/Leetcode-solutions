class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void cal(vector<int>& a,int i,vector<int> v)
    {
        if(i==n)
        {
            ans.push_back(v);
            return;
        }
        cal(a,i+1,v);
        v.push_back(a[i]);
        cal(a,i+1,v);
    }
    vector<vector<int>> subsets(vector<int>& a) {
        n=a.size();
        ans.clear();
        vector<int> v;
        cal(a,0,v);
        return ans;
    }
};