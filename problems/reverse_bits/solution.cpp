class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        const int nosOfBits = sizeof(n) * 8;
        uint32_t reversed = 0;
        for (int i = 0; i < nosOfBits; i++) {
            if (n & (1 << i)) {
                reversed |= (1 << (nosOfBits-i-1));
            }
        }
        return reversed;
        
    }
};