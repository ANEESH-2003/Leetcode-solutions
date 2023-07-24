class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n<0 && n!=-2147483648)
        {
            n*=-1;
            x=1/x;
        }
        double a=myPow(x,n/2);
        if(abs(n)%2)
            return a*a*x;
        return a*a;
    }
};