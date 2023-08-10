class Solution {
public:
    bool search(vector<int>& v, int t) {
        int l=0,r=v.size()-1;
        int mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(v[mid]==t)
                return 1;
            if(v[l]==v[mid] && v[r]==v[mid])
            {
                l++;
                r--;
            }
            else if(v[mid]>v[r])
            {
                //rotation hai aur mid left mien hai pivot ke
                if(v[mid]>t && v[l]<=t)
                    r=mid-1;
                else
                    l=mid+1;
            }
            else if(v[mid]<v[l])
            {
                //rotation hai aur mid right mien hai pivot ke
                if(v[mid]<t && t<=v[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
            else
            {
                //sab theek hai normal bineary search lagao
                if(v[mid]>t)
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        return 0;
        //[1,1,1,1,1//,1,1,1,1//,1,//1,1,1,2,//1,1,1,1,1]

    }
};