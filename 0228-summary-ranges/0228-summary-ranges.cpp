class Solution {
public:
    string cal(int n)
    {
        return to_string(n);
    }
    vector<string> summaryRanges(vector<int>& v) {
        vector<string> ans;
        string x="";
        if(v.size()==0)
            return ans;
        x+=cal(v[0]);
        int p=v[0];
        int c=1;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]!=p+1)
            {
                if(c>1)
                {
                    x+="->";
                    x+=cal(p);
                }
                ans.push_back(x);
                x=cal(v[i]);
                p=v[i];
                c=1;
            }
            else
            {
                p=v[i];
                c++;
            }
        }
        if(c>1)
        {
            x+="->";
            x+=cal(p);
        }
        ans.push_back(x);
        return ans;
    }
};