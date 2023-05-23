class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> p;
    int x;
    KthLargest(int k, vector<int>& nums) {
        x=k;
        for(auto i:nums)
        {
            if(p.size()!=k)
                p.push(i);
            else
            {
                if(p.top()<i)
                {
                    p.pop();
                    p.push(i);
                }
            }
        }
    }
    
    int add(int i) {
        if(p.size()!=x)
            p.push(i);
        else
        {
            if(p.top()<i)
            {
                p.pop();
                p.push(i);
            }
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */