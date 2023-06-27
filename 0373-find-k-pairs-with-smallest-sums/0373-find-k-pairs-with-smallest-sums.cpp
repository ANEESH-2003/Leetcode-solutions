class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size();
        int n=nums2.size();
        priority_queue<pair<int,pair<int,int>>> p;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=nums1[i]+nums2[j];
                if(p.size() < k) p.push({sum,{nums1[i],nums2[j]}});
                else if(sum < p.top().first) {
                    p.pop();
                    p.push({sum,{nums1[i],nums2[j]}});
                }
                else break;
            }
        }
        vector<vector<int>> ans;
        while(!p.empty()){
            auto it=p.top();
            ans.push_back({it.second.first,it.second.second});
            p.pop();
        }
        return ans;
    }
};