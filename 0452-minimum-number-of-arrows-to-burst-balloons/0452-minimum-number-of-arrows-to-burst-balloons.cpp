class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b)
    {
        if(a[0]<b[0])
        {
            return 1;
        }
        else if(a[0]==b[0] && a[1]<b[1])
            return 1;
        return 0;
    }
    int findMinArrowShots(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),comp);
        int x=0;
        int n=v.size();
        int r=v[0][1];
        for(int i=1;i<n;i++)
        {
            if(v[i][0]<=r)
            {
                if(v[i][1]<=r)
                    r=v[i][1];
            }
            else
            {
                x++;
                r=v[i][1];
            }
        }
        x++;
        return x;
        /*for(auto i:v)
        {
            for(auto j:i)
                cout<<j<<" ";
            cout<<"\n";
        }
        return 1;*/
    }
};