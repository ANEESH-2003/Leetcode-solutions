class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        vector<int> v(n+2,0);
        vector<int> a(n+2,0);
        int x=0;
        for(int i=1;i<=n+1;i++)
        {
            v[i]=x;
            if(i<n && s[i-1]=='N')
            {
                x++;
            }
        }
        x=0;
        for(int i=n;i>=0;i--)
        {
            if(i>0 && s[i-1]=='Y')
                x++;
            a[i]=x;
        }
        int mini=1;
        for(int i=1;i<=n+1;i++)
        {
            a[i]+=v[i];
            if(a[i]<a[mini])
                mini=i;
        }
        /*for(int i=0;i<=n+1;i++)
            cout<<i<<" "<<a[i]<<"\n";*/
        return mini-1;
    }
};