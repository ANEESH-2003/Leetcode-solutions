class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int a=1;
        int n=v.size();
        int l=0,r=0;
        int maxi=0;
        while(r<n)
        {
            a*=v[r];
            r++;
            if(a)
                maxi=max(maxi,r-l);
            else
            {
                a=1;
                l=r;
            }
        }
        return maxi;
    }
};