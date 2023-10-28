class Solution {
public:
    int countVowelPermutation(int n) {
        int mod=1e9+7;
        vector<vector<int>> v(n,vector<int>(5,0));
        for(int i=0;i<5;i++)
        {
            v[0][i]=1;
        }
        for(int i=1;i<n;i++)
        {
            v[i][0]=(v[i-1][1]+(v[i-1][4]+v[i-1][2])%mod)%mod;
            v[i][1]=(v[i-1][0]+v[i-1][2])%mod;
            v[i][2]=(v[i-1][1]+v[i-1][3])%mod;
            v[i][3]=v[i-1][2]%mod;
            v[i][4]=(v[i-1][3]+v[i-1][2])%mod;
        }
        int ans=0;
        for(auto i:v[n-1])
            ans=(ans+i)%mod;
        return ans;
    }
};