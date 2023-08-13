class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n=v.size();
        int ans=0;
        stack<pair<int,int>> l;
        vector<int> f(n,0);
        l.push({INT_MIN,-1});
        for(int i=0;i<n;i++)
        {
            while(l.top().first>=v[i])
                l.pop();
            int g=i-l.top().second;
            f[i]=g;
            l.push({v[i],i});
        }
        /*for(auto i:f)
            cout<<i<<' ';
        cout<<"\n";*/
        stack<pair<int,int>> r;
        r.push({INT_MIN,n});
        for(int i=n-1;i>=0;i--)
        {
            while(r.top().first>=v[i])
                r.pop();
            int g=r.top().second-i;
            f[i]+=g;
            r.push({v[i],i});
        }
        /*for(auto i:f)
            cout<<i<<' ';
        cout<<"\n";*/
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(f[i]-1)*v[i]);
        }
        return ans;
    }
};