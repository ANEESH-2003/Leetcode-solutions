class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=(nums.size()%(i+1))==0?nums[i]*nums[i]:0;
        }
        return ans;
    }
};