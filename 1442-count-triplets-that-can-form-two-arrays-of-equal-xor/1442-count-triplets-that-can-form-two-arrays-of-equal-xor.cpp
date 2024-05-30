class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, vector<int>>mp;
        int val=0, ans=0;
        for(int i=0; i<arr.size(); i++){
          val^=arr[i];
            if(val==0){
                ans+=i;
            }
            if(mp.find(val)==mp.end()){
                vector<int>v={i,1,0};
                mp[val]=v;
            }
            else{
                ans+=(i-mp[val][0]-1)*mp[val][1]-mp[val][2];
                mp[val][1]+=1;
                mp[val][2]+=(i-mp[val][0]);
            }
        }
        return ans;
    }
};