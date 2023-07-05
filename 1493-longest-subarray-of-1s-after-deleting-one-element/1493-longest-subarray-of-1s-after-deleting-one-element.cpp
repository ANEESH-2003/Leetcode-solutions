class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> p;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==1)
            {
                int l=i,r=i;
                while(r<n && v[r]==1)
                {
                    r++;
                }
                p.push_back({l,r-1});
                maxi=max(maxi,r-l);
                i=r;
            }
        }
        if(p.size()==0)
            return 0;
        if(p[0][0]==0 && p[0][1]==n-1)
            return n-1;
        for(int i=1;i<p.size();i++)
        {
            if(p[i-1][1]+2==p[i][0])
                maxi=max(maxi,p[i-1][1]-p[i-1][0]+1+p[i][1]-p[i][0]+1);
        }
        return maxi;
    }
};