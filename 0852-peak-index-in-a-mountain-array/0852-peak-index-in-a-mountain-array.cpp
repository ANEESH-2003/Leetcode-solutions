class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1;
        int mid;
        while(1)
        {
            mid=l+((r-l)/2);
            int lm=v[mid-1];
            int rm=v[mid+1];
            int m=v[mid];
            if(lm>m && m>rm)
                r=mid;
            else if(lm<m && m<rm)
                l=mid;
            else
                return mid;
        }
        return -1;
    }
};