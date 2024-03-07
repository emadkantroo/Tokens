#include <cstdint> // For uint32_t

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1; // Shift result to the left by 1
        result |= (n & 1); // Add the rightmost bit of n to result
        n >>= 1; // Shift n to the right by 1 to process the next bit
    }
    return result;
}

//python3
class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0
        for i in range(32):
            bit=(n>>i) & 1
            result = result | bit<<(31-i)

        return result
