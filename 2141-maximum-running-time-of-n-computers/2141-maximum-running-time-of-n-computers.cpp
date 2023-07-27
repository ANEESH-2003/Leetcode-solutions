class Solution {
public:
    bool cal(vector<int>& v,long long mid,int n)
    {
        long long x=0;
        for(auto i:v)
            x+=min((long long)i,mid);
        return x>=mid*n;
    }
    long long maxRunTime(int n, vector<int>& v) {
        long long r=0;
        for(auto i:v)
            r+=(long long)i;
        long long l=0,mid;
        r/=n;
        while(l<r)
        {
            mid=(l + r + 1) / 2;
            if(cal(v,mid,n))
            {
                l=mid;
            }
            else
                r=mid-1;
        }
        return l;
    }
};