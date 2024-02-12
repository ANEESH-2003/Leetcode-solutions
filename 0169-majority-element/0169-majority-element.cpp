class Solution {
public:
    int majorityElement(vector<int>& v) {
        int c=1,n=v[0];
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==n)
                c++;
            else
                c--;
            if(c==0)
            {
                n=v[i];
                c++;
            }
        }
        return n;
    }
};