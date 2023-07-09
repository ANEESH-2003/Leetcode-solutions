class Solution {
public:
    int largestVariance(string s) {
        int n=s.size();
        int ans=0;
        vector<int> v(26,0);
        for(auto i:s)
        {
            v[i-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(i==j || v[i]==0 || v[j]==0)
                    continue;
                int bigcnt=0;
                int smcnt=0;
                int rem=v[j];
                for(auto k:s)
                {
                    if((int)(k-'a')==i)
                        bigcnt++;
                    if((int)(k-'a')==j)
                    {
                        smcnt++;
                        rem--;
                    }
                    if(smcnt)
                        ans=max(ans,bigcnt-smcnt);
                    if(bigcnt-smcnt<0 && rem)
                    {
                        bigcnt=0;
                        smcnt=0;
                    }
                }
            }
        }
        return ans;
    }
};