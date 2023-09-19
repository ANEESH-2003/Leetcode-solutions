class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int s=v[0],f=v[v[0]];
        while(s!=f)
        {
            s=v[s];
            f=v[v[f]];
        }
        s=0;
        while(s!=f)
        {
            s=v[s];
            f=v[f];
        }
        return s;
    }
};