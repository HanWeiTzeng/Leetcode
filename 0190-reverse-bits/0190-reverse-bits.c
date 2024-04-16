//  最聰明的方式：想看看!!

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0u;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) + (n >> i & 1);
    }
    return result;
}
/*
=====================================
uint32_t reverseBits(uint32_t n) {
    for (int i = 0; i < 16; i++) {
        int c = n & (1u << i);
        int a = ((n >> (31-i)) & 1u);
        if (c != 0 && a == 0) {
            n |= 1u << (31-i);
            n &= ~(1u << i);
        } else if (c == 0 && a != 0) {
            n &= ~(1u << (31-i));
            n |= 1u << i;
        }

    }
    return n;
}
*/