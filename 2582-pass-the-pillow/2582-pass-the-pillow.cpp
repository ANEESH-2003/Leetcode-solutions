class Solution {
public:
    int passThePillow(int n, int t) {
        if((t/(n-1))%2)
        {
            return n-(t%(n-1));
        }
        return (t%(n-1))+1;
    }
};