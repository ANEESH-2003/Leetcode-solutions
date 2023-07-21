class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n=v.size();
        vector<int> a(n,1);
        int maxi=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(v[j]>v[i])
                    a[i]=max(a[i],a[j]+1);
            }
            maxi=max(maxi,a[i]);
        }
        return maxi;
    }
};