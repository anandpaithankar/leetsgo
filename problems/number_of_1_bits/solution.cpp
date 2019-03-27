class Solution {
public:
    int hammingWeight(uint32_t n) {
        const int nosOfBits = sizeof(n) * 8;
        int count = 0;
        for (int i = 0; i < nosOfBits; i++) {
            if (n & (1 << i)) {
                count++;
            }
        }
        return count;
    }
};