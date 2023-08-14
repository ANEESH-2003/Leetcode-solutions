class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int ans=INT_MAX;
        int n=a.size();
        int m=b.size();
        for(int i=0;i<n;i++)
        {
            int k=i;
            bool d=1;
            for(int j=0;j<m;j++,k=(k+1)%n)
            {
                if(b[j]!=a[k])
                {
                    d=0;
                    break;
                }
            }
            if(d)
                ans=min(ans,(i+m)/n+((i+m)%n?1:0));
        }
        return ans==INT_MAX?-1:ans;
    }
};