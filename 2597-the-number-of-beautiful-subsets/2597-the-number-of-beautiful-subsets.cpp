class Solution {
public:

    int solve (vector<int>& arr, int k, vector<int>& temp, int idx = 0) {
        if (idx == arr.size()) {
            for (int i=0;i<temp.size();i++) {
                for (int j=i;j<temp.size();j++) {
                    if (abs(temp[i] - temp[j]) == k) return 0;
                }
            }
            return 1;
        }
        int ans = 0;
        temp.push_back(arr[idx]);
        ans += solve(arr, k, temp, idx + 1);
        temp.pop_back();
        ans += solve(arr, k, temp, idx + 1);
        return ans;
    }

    int beautifulSubsets(vector<int>& arr, int k) {
        vector<int> temp;
        return solve(arr, k, temp) - 1;
    }
};