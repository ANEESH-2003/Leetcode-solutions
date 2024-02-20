class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int pxor=0;
        for(int i=0;i<nums.size();i++)
        {
            pxor^=nums[i];
        }
        int x=0;
        int n=nums.size();
        if(n%4==0)
            x=n;
        else if(n%4==1)
            x=1;
        else if(n%4==2)
            x=n+1;
        else
            x=0;
        int i=x^pxor;
        return i;
    }
};