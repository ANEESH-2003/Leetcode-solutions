class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int maxi=0;
        int l=0,r=0;
        for(;r<c.size() && r<m;r++)
        {
            maxi+=g[r]?c[r]:0;
        }
        int cur=maxi;
        while(r<c.size())
        {
            cur-=g[l]?c[l]:0;
            cur+=g[r]?c[r]:0;
            r++;
            l++;
            maxi=max(maxi,cur);
        }
        int s=0;
        for(int i=0;i<c.size();i++)
            s+=g[i]?0:c[i];
        return s+maxi;
    }
};