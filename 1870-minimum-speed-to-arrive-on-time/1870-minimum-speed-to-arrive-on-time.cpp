class Solution {
public:
    bool cal(vector<int>& v,double h,int mid)
    {
        double x=0;
        for(auto i:v)
        {
            x=ceil(x);
            x+=(double)i/mid;
            if(x>h)
                return 0;
        }
        return 1;
    }
    int minSpeedOnTime(vector<int>& v, double h) {
        int n=v.size();
        if(ceil(h)<n)
            return -1;
        int l=1,r=1e7;
        int mid;
        while(l<r)
        {
            mid=l+(r-l)/2;
            //cout<<mid<<"\n";
            if(cal(v,h,mid))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};