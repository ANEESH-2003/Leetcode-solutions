class Solution {
public: 
    int numOfWays(vector <int> & nums) {
        long long mod = 1e9 + 7;
        int n = nums.size();
        dp.resize(n + 1);
        for (int i = 0; i < n + 1; i++) {
            dp[i] = vector < long long > (i + 1, 1);
            for (int j = 1; j < i; ++j) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
            }
        }
        long long ans = dfs(nums, mod);
        return (ans % mod - 1) % mod;
    }
    
    vector <vector<long long>> dp;
    long long dfs(vector <int> & nums, long long mod) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector <int> left, right;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long left_res = dfs(left, mod) % mod;
        long long right_res = dfs(right, mod) % mod;

        int left_len = left.size(), right_len = right.size();
        return (((dp[n - 1][left_len] * left_res) % mod) * right_res) % mod;
    }
};