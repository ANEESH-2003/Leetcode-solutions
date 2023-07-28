class Solution {
public:
    int cal(vector<int>& nums,int l,int r,int p)
    {
        if(l>r)
            return 0;
        int first=p*nums[l]+cal(nums,l+1,r,-p);
        int last=p*nums[r]+cal(nums,l,r-1,-p);
        return p==-1?min(first,last):max(first,last);
    }
    bool PredictTheWinner(vector<int>& nums) {
        return cal(nums,0,nums.size()-1,1)>=0;
    }
};