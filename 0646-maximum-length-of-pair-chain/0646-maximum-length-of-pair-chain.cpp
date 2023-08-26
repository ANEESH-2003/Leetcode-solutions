class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        vector<int> v(2002,2001);
        for(auto i:p)
        {
            v[i[0]+1000]=min(v[1000+i[0]],1000+i[1]);
        }
        vector<int> ans(2002,0);
        for(int i=2000;i>=0;i--)
        {
            ans[i]=ans[i+1];
            if(v[i]==2001)
                continue;
            else
                ans[i]=max(ans[i],1+ans[v[i]+1]);
            //cout<<i<<" "<<ans[i]<<" "<<v[i]+1<<endl;
        }
        return ans[0];
    }
};