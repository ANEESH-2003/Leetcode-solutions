class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& m, int k) {
        int n=m.size();
        int x=m[0].size();
        vector<int> v(n);
        int c=0;
        for(auto i:m)
        {
            int ans=x;
            int l=0,r=x-1;
            int mid;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(i[mid]==0)
                {
                    ans=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            v[c++]=ans;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>> p;
        for(int i=0;i<n;i++)
        {
            if(p.size()==k)
            {
                if(p.top().first>v[i])
                {
                    p.pop();
                    p.push({v[i],i});
                }
            }
            else
                p.push({v[i],i});
        }
        vector<int> f;
        while(!p.empty())
        {
            f.push_back(p.top().second);
            p.pop();
        }
        reverse(f.begin(),f.end());
        return f;
    }
};