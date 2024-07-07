class Solution {
public:
    int numWaterBottles(int a, int b,int s=0) {
        return a?a+numWaterBottles((a+s)/b,b,(a+s)%b):0;
    }
};