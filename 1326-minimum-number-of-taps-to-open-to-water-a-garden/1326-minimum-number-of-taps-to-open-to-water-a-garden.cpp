class Solution {
public:
    int minTaps(int n, vector<int>& r) {
        vector<int> v(n+1,0);
        for(int i=0;i<r.size();i++)
        {
            int l=max(0,i-r[i]);
            int ri=min(n,i+r[i]);
            v[l]=max(v[l],ri-l);
        }
        int cnt=0,curend=0,furthurcur=0;
        for(int i=0;i<n;i++)
        {
            if(i>furthurcur)
                return -1;
            furthurcur=max(furthurcur,i+v[i]);
            if(i==curend)
            {
                curend=furthurcur;
                cnt++;
            }
        }
        return furthurcur>=n?cnt:-1;
    }
};