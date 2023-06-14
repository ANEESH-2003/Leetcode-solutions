class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size())
            return findMedianSortedArrays(b,a);
        int l=0,r=a.size();
        int na=a.size();
        int nb=b.size();
        while(l<=r)
        {
            int mid=(l+r)>>1;
            int mid2=((na+nb+1)>>1)-mid;
            int l1=(mid==0)?INT_MIN:a[mid-1];
            int l2=(mid2==0)?INT_MIN:b[mid2-1];
            int r1=(mid==na)?INT_MAX:a[mid];
            int r2=(mid2==nb)?INT_MAX:b[mid2];
            if(l1<=r2 && l2<=r1)
            {
                if((na+nb)%2)
                {
                    return max(l1,l2);
                }
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2)
                r=mid-1;
            else
                l=mid+1;
        }
        return 0.0;
    }
};