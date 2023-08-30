class Solution {
public:
    long long minimumReplacement(vector<int>& v) {
        long long ans=0;
        int n=v.size();
        int p=v[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(v[i]>p)
            {
                long long c=v[i]/p;
                c+=(v[i]%p)?1:0;
                //cout<<i<<" "<<c<<" "<<p<<" "<<"\n";
                p=v[i]/c;
                ans+=c-1;
            }
            else
                p=v[i];
        }
        return ans;
    }
};