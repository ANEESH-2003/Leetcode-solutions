class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long , int>>dq;
        long long sum = 0;
        int min_len = INT_MAX;
        for(int i = 0 ; i<n ;i++){
            sum += nums[i];
            if(sum >= k)min_len = min(min_len , i+1);
            while(!dq.empty() && sum-dq.front().first >=k){
                min_len = min(min_len ,i-dq.front().second);
                dq.pop_front();
            }
            while(!dq.empty() && dq.back().first>=sum){
                dq.pop_back();
            }
            dq.push_back({sum,i});
        }
        if(min_len == INT_MAX)return -1;
        return min_len;
    }
};