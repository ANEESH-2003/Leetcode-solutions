class Solution {
    public:
    int numSquares(int n) {
        while (n % 4 == 0)    n /= 4;
        if (n % 8 == 7)    return 4;
        int m = sqrt(n);
        if (m * m == n)    return 1;
        if (n % 2 == 0)    n >>= 1;
        if (n % 4 == 3)    return 3;
        for (int i = 3; i * i < n; i += 4)
            if (n % i == 0) {
                bool odd = true;
                n /= i;
                while (n % i == 0) {
                    odd = !odd;
                    n /= i;
                }
                if (odd)    return 3;
            }
        return 2;
    }
};