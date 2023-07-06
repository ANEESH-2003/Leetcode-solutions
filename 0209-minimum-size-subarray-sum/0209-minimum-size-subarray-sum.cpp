class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int l=0,r=0;
        int mini=INT_MAX;
        while(r<n)
        {
            sum+=nums[r];
            r++;
            while(sum>=target && l<r)
            {
                mini=min(mini,r-l);
                sum-=nums[l++];
            }
        }
        return mini==INT_MAX?0:mini;
        
    }
};