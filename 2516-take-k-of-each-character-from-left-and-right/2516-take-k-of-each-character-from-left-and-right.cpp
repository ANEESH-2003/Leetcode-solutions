class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        int ans=-1;
        vector<int> v(3,0);
        for(auto i:s)
        {
            v[i-'a']++;
        }
        for(auto i:v)
        {
            if(i<k)
                return -1;
        }
        for(int i=0,j=0;i<n;i++)
        {
            v[s[i]-'a']--;
            if(v[s[i]-'a']<k)
            {
                while(j<n && v[s[i]-'a']<k)
                    v[s[j++]-'a']++;
            }
            ans=max(ans,i-j+1);
        }
        return n-ans;
    }
};