class Solution {
public:
    long long maximumValueSum(vector<int>& a, int k, vector<vector<int>>& v) {
        long long ans = 0;
        int d = 1e9;
        int count = 0;
        int n = a.size();
        for(int i = 0 ; i <n ;i++){
            int x = a[i];
            int y = a[i]^k;

            if(y>x){
                count++;
                ans+=y;
               
            }
            else ans+=x;
             d = min(d , abs(y-x));
        }

        if(count%2) ans-=d; 
            
        return ans ;
    }
};