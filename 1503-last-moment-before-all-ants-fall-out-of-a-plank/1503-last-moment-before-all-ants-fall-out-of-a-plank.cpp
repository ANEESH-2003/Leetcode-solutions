class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi=0;
        for(auto i:left)
            maxi=max(maxi,i);
        for(auto i:right)
            maxi=max(maxi,n-i);
        return maxi;
    }
};