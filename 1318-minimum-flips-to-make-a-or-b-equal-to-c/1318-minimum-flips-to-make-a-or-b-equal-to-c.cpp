class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x=(a|b);
        int n=0;
        int ans=0;
        while(c || x)
        {
           // cout<<x<<" "<<c<<" ";
            if(x&1 && !(c&1))
            {
                if(a&(1<<n))
                    ans++;
                if(b&(1<<n))
                    ans++;
            }
            else if(c&1 && !(x&1))
            {
                ans++;
            }
            //cout<<ans<<"\n";
            x=x>>1;
            c=c>>1;
            n++;
        }
        return ans;
    }
};