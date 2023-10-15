class Solution {
public:
    int n;
    int mod=1e9+7;
    int l;
    int cal(int s,int i,vector<vector<int>>& v)
    {
        //cout<<s<<" "<<i<<"\n";
        if(i>l)
            return 0;
        if(s==0)
            return v[i][s]=(i==0)?1:0;
        if(v[i][s]!=-1)
            return v[i][s];
        int ans=cal(s-1,i,v);
        if(i!=n-1)
            ans=(ans+cal(s-1,i+1,v))%mod;
        if(i!=0)
            ans=(ans+cal(s-1,i-1,v))%mod;
        return v[i][s]=ans;
    }
    int numWays(int s, int N) {
        n=N;
        l=min(n-1,s/2);
        vector<vector<int>> v(l+1,vector<int>(s+1,0));
        v[0][0]=1;
        for(int j=1;j<=s;j++)
        {
            for(int i=0;i<=l;i++)
            {
                v[i][j]=v[i][j-1];
                if(i>0)
                    v[i][j]=(v[i][j]+(v[i-1][j-1]))%mod;
                if(i<l)
                    v[i][j]=(v[i][j]+(v[i+1][j-1]))%mod;
            }
        }
        return v[0][s];
        //return cal(s,0,v);
    }
};