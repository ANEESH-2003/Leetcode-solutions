class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int n=v.size();
        int l=0,r=0;
        int maxi=0;
        while(r<n)
        {
            if(v[r++])
                maxi=max(maxi,r-l);
            else
            {
                l=r;
            }
        }
        return maxi;
    }
};