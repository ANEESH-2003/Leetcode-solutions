class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1;
        int lm=0,rm=0;
        int ans=0;
        while(l<r)
        {
            if(v[l]<=v[r])
            {
                lm=max(lm,v[l]);
                ans+=lm-v[l];
                l++;
            }
            else
            {
                rm=max(rm,v[r]);
                ans+=rm-v[r];
                r--;
            }
        }
        return ans;
    }
};