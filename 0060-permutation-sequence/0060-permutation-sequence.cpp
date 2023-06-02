class Solution {
public:
    string getPermutation(int n, int k) {
        set<int> s;
        int t=1;
        for(int i=1;i<=n;i++)
        {
            t*=i;
            s.insert(i);
        }
        k--;
        t/=n;
        string ans="";
        while(n!=1)
        {
            auto i=next(s.begin(),(k/t));
            ans+=(char)(*i+'0');
            s.erase(i);
            k=k-(k/t)*t;
            n--;
            t/=n;
        }
        ans+=(char)(*s.begin()+'0');
        return ans;
    }
};