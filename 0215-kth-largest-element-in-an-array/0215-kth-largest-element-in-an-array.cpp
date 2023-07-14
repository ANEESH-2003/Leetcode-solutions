class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> p;
        for(auto i:nums)
        {
            if(p.size()!=k)
            {
                p.push(i);
            }
            else if(p.top()<i)
            {
                p.pop();
                p.push(i);
            }
        }
        return p.top();
    }
};