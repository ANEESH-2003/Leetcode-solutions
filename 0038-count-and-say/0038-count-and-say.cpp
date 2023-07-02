class Solution {
public:
    string cal(string s,int n)
    {
        if(n==0)
            return s;
        string x="";
        for(int i=0;i<s.size();i++)
        {
            int c=0;
            int j=i;
            while(j<s.size())
            {
                if(s[j]!=s[i])
                    break;
                j++;
                c++;
            }
            j--;
            x+=to_string(c);
            x+=s[i];
            i=j;
        }
        return cal(x,n-1);
    }
    string countAndSay(int n) {
        string s="1";
        return cal(s,n-1);
    }
};