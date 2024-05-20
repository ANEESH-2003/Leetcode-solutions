class Solution {
    int ans = 0;
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum |= nums[i];
        }
        return sum << (nums.size()-1);
    }
};