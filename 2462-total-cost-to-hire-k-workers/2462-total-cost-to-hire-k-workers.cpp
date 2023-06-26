class Solution {
public:
    long long totalCost(vector<int>& v, int k, int n) {
        priority_queue<int,vector<int>,greater<int>> p,q;
        long long ans=0;
        int i=0,j=v.size()-1;
        while(k--)
        {
            while(p.size()<n && i<=j)
                p.push(v[i++]);
            while(q.size()<n && i<=j)
                q.push(v[j--]);
            int a=INT_MAX,b=INT_MAX;
            if(!p.empty())
            {
                a=p.top();
                
            }
            if(!q.empty())
            {
                b=q.top();
                
            }
            if(a<=b)
            {
                ans+=a;
                p.pop();
            }
            else
            {
                ans+=b;
                q.pop();
            }
        }
        return ans;
    }
};