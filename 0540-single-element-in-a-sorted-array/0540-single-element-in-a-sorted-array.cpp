class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1;
        int mid;
        int ans=0;
        while(l<r)
        {
            mid=l+r;
            mid=mid>>1;
            if(v[mid]==v[mid^1])
                l=mid+1;
            else
                r=mid;
        }
        return v[l];
    }
};