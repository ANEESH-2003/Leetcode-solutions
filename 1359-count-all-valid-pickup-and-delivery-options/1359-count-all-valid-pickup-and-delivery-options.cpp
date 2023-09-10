int dp[501];
class Solution {
public:
    long long mod = 1e9+7;
    int solve(int n){
        if(n == 1) return 1;
        if(dp[n] != 0) return dp[n];
        long long ans = (countOrders(n-1))%mod;
        long long ans1 = (2*n-1)*n;
        long long temp= ((ans1%mod)*(ans%mod))%mod;
        return dp[n] = temp;
    }
    int countOrders(int n) {
        return solve(n);


    }
};