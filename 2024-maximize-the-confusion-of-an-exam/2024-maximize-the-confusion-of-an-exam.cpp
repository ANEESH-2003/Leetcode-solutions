class Solution {
public:
    int cal(string& s,int& k,char c)
    {
        int n=s.size();
        int l=0,r=0;
        int x=0;
        int maxi=0;
        while(r<n)
        {
            if(s[r]==c)
                x++;
            r++;
            while(x>k)
            {
                if(s[l]==c)
                    x--;
                l++;
            }
            maxi=max(maxi,r-l);
        }
        return maxi;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(cal(answerKey,k,'T'),cal(answerKey,k,'F'));
    }
};