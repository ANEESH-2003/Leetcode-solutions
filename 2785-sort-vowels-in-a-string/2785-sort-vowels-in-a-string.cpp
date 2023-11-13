class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        vector<int> v;
        string x="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' )
            {
                x+=s[i];
                v.push_back(i);
            }
        }
        sort(x.begin(),x.end());
        for(int i=0;i<v.size();i++)
        {
            s[v[i]]=x[i];
        }
        return s;
    }
};