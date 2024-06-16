class Solution {
public:
    int minPatches(vector<int>& v, int n) {
        long long i=0,cursum=1,ans=0;
        while(cursum<=n) {
            if(i<v.size() && v[i]<=cursum) {
                cursum+=v[i];
                i++;
            }
            else {
                ans++;
                cursum*=2;
            }
        }
        return ans;
    }
};