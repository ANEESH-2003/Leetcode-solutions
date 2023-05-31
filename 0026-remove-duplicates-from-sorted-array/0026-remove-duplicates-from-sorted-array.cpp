class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v(202,0);
        int i=0;
        for(int j=0;j<nums.size();j++)
        {
            if(v[nums[j]+100])
                continue;
            v[nums[j]+100]++;
            nums[i]=nums[j];
            i++;
        }
        return i;
    }
};