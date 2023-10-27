class Solution {
public:
    void cal(int l,int r,string& s,string& ans,int n)
    {
        string x="";
        while(l>=0 && r<n)
        {
            if(s[l]==s[r])
            {
                l--;
                r++;
            }
            else
                break;
        }
        r--;
        l++;
        //cout<<l<<" "<<r<<"\n";
        if(r-l+1>ans.size())
        {
            ans=s.substr(l,r-l+1);
        }
    }
    string longestPalindrome(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            cal(i,i,s,ans,n);
            cal(i-1,i,s,ans,n);
        }
        return ans;
    }
};