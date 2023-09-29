class Solution {
public:
    bool isMonotonic(vector<int>& v) {
        for(int i=1;i<v.size();i++)
        {
            if((long long)(v[i]-v[i-1])*(long long)(v[v.size()-1]-v[0])<0)
                return 0;
            else if(v[i]!=v[i-1] && v[v.size()-1]==v[0])
                return 0;
        }
        return 1;
    }
};