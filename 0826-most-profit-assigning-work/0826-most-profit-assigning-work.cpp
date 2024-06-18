class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        
        vector<pair<int,int>> vp;
        for( int i = 0; i < p.size() ; i++){
            vp.push_back({d[i] , p[i]});
        }

        sort( vp.begin() , vp.end());

        for( int i = 1; i < vp.size() ; i++){

            vp[i].second = max( vp[i-1].second , vp[i].second);
        }

        int res = 0;

        for( int i = 0; i < w.size() ; i++){

            int start = 0 , end = vp.size()-1;
            int mx = -1;
            while( start <= end){

                int mid = (start + end )/2;

                if( vp[mid].first <= w[i]){

                    mx = mid;
                    start = mid+1;
                }
                else end = mid-1;
            }



            if(mx != -1) res += vp[mx].second;
        }

        return res;

    }
};