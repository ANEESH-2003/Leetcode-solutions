class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> ans;
        sort(v.begin(),v.end());
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(i!=0 && v[i]==v[i-1])
                continue;
            for(int j=i+2;j<n;j++)
            {
                if(j!=n-1 && v[j]==v[j+1])
                    continue;
                int vl=i+1,vr=j-1;
                int mid=(vl+vr)/2;
                while(vl<=vr)
                {
                    mid=(vl+vr)/2;
                    int s=v[mid]+v[i]+v[j];
                    //cout<<l<<" "<<r<<" "<<vl<<" "<<vr<<" "<<mid<<" "<<s<<"\n";
                    if(s==0)
                    {
                        ans.push_back({v[i],v[mid],v[j]});
                        break;
                    }
                    else if(s<0)
                        vl=mid+1;
                    else
                        vr=mid-1;
                }
            }
        }
        return ans;
    }
};