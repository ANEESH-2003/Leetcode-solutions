class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b, int k) {
        long long n=a.size();
        vector<pair<long long,long long>> v;
        for(long long i=0;i<n;i++)
        {
            v.push_back({b[i],a[i]});
        }
        sort(v.begin(),v.end());
        long long s=0;
        priority_queue<long long,vector<long long>,greater<long long>> p;
        long long maxi=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i>=n-k)
            {
                p.push(v[i].second);
                s+=v[i].second;
            }
            else
            {
                if(p.top()<v[i].second)
                {
                    s-=p.top();
                    p.pop();
                    p.push(v[i].second);
                    s+=v[i].second;
                    maxi=max(maxi,s*v[i].first);
                }
            }
            if(i==n-k)
            {
                maxi=max(maxi,s*v[i].first);
            }
            //cout<<p.top()<<" "<<maxi<<"\n";
        }
        return maxi;
    }
};