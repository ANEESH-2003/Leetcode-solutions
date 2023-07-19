class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),comp);
        int ans=-1;
        int p=0;
        //for(auto i:v)
          //  cout<<i[0]<<" "<<i[1]<<"\n";
        for(int i=0;i<v.size();i++)
        {
            if(v[i][0]>=v[p][1])
                p=i;
            else
                ans++;
        }
        return ans;
    }
};