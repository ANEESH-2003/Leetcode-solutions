class Solution{
public:
     int maxFrequencyElements(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<int,int> mp;
         int count= 0;
         int maxFreq= 0;

        for(int i=0; i<n; i++)
        {
           mp[nums[i]]++;
           if(maxFreq < mp[nums[i]])
           {
               maxFreq= mp[nums[i]];
               count= mp[nums[i]];
           }

          else if(maxFreq== mp[nums[i]])
           {
               count+= mp[nums[i]];
           }
        }
    return count;
     }
};
