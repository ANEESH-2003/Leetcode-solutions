class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCount = 0;
        int zeroIndex = -1;
        vector<int> ans(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            if (nums[i] != 0){
                product *= nums[i];
            }
            else {
                zeroCount++;
                zeroIndex = i;
                if(zeroCount > 1) return ans;
            }
        }
        if(zeroCount == 1) {
            ans[zeroIndex] = product;
        }
        else{
            for(int i=0; i<nums.size(); i++){
                ans[i] = product/nums[i];
            }
        }
        return ans;
    }
};