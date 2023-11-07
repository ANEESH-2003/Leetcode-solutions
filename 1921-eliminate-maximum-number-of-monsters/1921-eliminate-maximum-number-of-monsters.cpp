class Solution {
public:
    int eliminateMaximum(vector<int>& d, vector<int>& s) {
        int n=d.size();
        for(int i=0;i<n;i++)
        {
            d[i]=d[i]/s[i]+(d[i]%s[i]?1:0);
        }
        sort(d.begin(),d.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(d[i]<=i)
                break;
            ans++;
        }
        return ans;
    }
};