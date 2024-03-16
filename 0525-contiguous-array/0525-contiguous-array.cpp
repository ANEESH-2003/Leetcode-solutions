class Solution {
public:
    int findMaxLength(vector<int>& v) {
        map<int,int> m;
        int n=v.size();
        int s=0;
        int ans=0;
        m[0]=-1;
        for(int i=0;i<n;i++)
        {
            s+=v[i]==1?1:-1;
            if(m.find(s)!=m.end())
            {
                ans=max(ans,i-m[s]);
            }
            else
                m[s]=i;
        }
        return ans;
    }
};