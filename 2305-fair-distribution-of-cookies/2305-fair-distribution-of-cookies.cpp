class Solution {
public:
    void cal(vector<int>& v,vector<int>& x,int k,int& maxi,int c)
    {
        if(c==x.size())
        {
            maxi=min(maxi,*max_element(v.begin(),v.end()));
            return;
        }
        for(int i=0;i<k;i++)
        {
            v[i]+=x[c];
            cal(v,x,k,maxi,c+1);
            v[i]-=x[c];
        }
    }
    int distributeCookies(vector<int>& x, int k) {
        vector<int> v(k,0);
        int maxi=INT_MAX;
        cal(v,x,k,maxi,0);
        return maxi;
    }
};