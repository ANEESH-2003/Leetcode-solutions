class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        int n=v.size();
        //if(n==k || k==1) return 0;
        vector<int> a;
        for(int i=0;i<n-1;i++)
        {
            a.push_back(v[i]+v[i+1]);
        }
        sort(a.begin(),a.end());
        long long ans=0;
        int x=k-1;
        for(int i=a.size()-1;i>=0 && x;i--,x--)
        {
            ans+=a[i];
        }
        x=k-1;
        for(int i=0;i<a.size() && x;x--,i++)
        {
            ans-=a[i];
        }
        return ans;
    }
};