class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        vector<int> ans;
        int n=nums.size();
       int pref[n];
       int suf[n];
       pref[0]=nums[0];
       suf[n-1]= nums[n-1];

       for(int i=1;i<n;i++){
           pref[i] = pref[i-1]+nums[i];
       }

       for(int j=n-2;j>=0;j--){
           suf[j] = suf[j+1]+nums[j];
       }
     
       for(int i=0;i<n;i++){
           int nl= i; // How many element left to nums[i];
           int nr = n-i-1; //How many element right to nums[i];

           int sumleft=0;
           int sumright= 0;

           if(i-1>=0){
               sumleft = nl*nums[i]-pref[i-1];
           }
           if(i+1<n){
               sumright= suf[i+1] - nr*nums[i];
           }

           ans.push_back(sumleft+sumright);
           
       }

        return ans;
    }
};