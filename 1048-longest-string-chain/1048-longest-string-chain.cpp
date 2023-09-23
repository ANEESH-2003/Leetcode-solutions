class Solution {
public:
    static bool mycomp(string a,string b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& w) {
        sort(w.begin(),w.end(),mycomp);
        int n=w.size();
        unordered_map<string,int> m;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            string s=w[i];
            int maxi=0;
            for(int j=0;j<s.size();j++)
            {
                string x=s.substr(0,j)+s.substr(j+1,s.size()-1);
                maxi=max(maxi,m[x]+1);
            }
            m[s]=maxi;
            ans=max(ans,maxi);
        }
        return ans;
    }
};