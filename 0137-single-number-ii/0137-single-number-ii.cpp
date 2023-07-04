class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans=0;
        vector<int> a;
        vector<int> b;
        int ne=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==-2147483648)
                ne++;
            else if(nums[i]<0)
                a.push_back(nums[i]*-1);
            else
                b.push_back(nums[i]);
            nums.pop_back();
        }
        if(ne==1)
            return -2147483648;
        for(int i=0;i<31;i++)
        {
            int count=0;
            
            for(int j=0;j<a.size();j++)
            {
                if((a[j]&(1<<i))!=0)
                {
                    count++;
                }
                
                
            }
            ans+=(count%3)*pow(2,i);
        }
        int ans2=0;
        for(int i=0;i<31;i++)
        {
            int count=0;
            
            for(int j=0;j<b.size();j++)
            {
                if((b[j]&(1<<i))!=0)
                {
                    count++;
                }
                
                
            }
            ans2+=(count%3)*pow(2,i);
        }
        if(ans)
            return ans*-1;
        return ans2;
    }
};