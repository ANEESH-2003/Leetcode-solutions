class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]==i+1 || v[i]<=0 || v[i]>=n)
                continue;
            else
            {
                int j=i;
                if(v[i]!=v[v[i]-1])
                    j--;
                swap(v[i],v[v[i]-1]);
                i=j;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(v[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};