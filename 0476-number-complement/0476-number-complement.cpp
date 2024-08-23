class Solution {
public:
    int findComplement(int num) {
        int numBits = static_cast<int>(std::log2(num)) + 1;
        unsigned int mask = (1U << numBits) - 1;
        return num ^ mask;
    }
};