class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n=v.size();
        vector<int> ans(n-k+1,INT_MIN);
        multiset<int> s;
        int l=n-1;
        int j=n-k;
        for(int i=n-1;i>=0;i--)
        {
            if(l-i==k)
                s.erase(s.find(v[l--]));
            s.insert(v[i]);
            if(n-k>=i)
            {
                ans[j--]=*s.rbegin();
            }
        }
        return ans;
    }
};