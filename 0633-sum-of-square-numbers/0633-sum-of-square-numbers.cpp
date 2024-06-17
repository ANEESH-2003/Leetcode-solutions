class Solution {
public:
    bool issquare(int x) {
        return floor(sqrt(x))==ceil(sqrt(x));
    }
    bool judgeSquareSum(int c) {
        int x=c;
        while(x>=0) {
            int t=sqrt(x);
            if(issquare(c-(t*t)))
                return 1;
            x=(t*t)-1;
        }
        return 0;
    }
};