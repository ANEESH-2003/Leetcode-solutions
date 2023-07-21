class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int maxi=1;
        int mini=1;
        for(auto i:nums)
        {
            if(i<0)
                swap(maxi,mini);
            maxi=max(maxi*i,i);
            mini=min(mini*i,i);
            ans=max(ans,maxi);
        }
        return ans;
    }
};