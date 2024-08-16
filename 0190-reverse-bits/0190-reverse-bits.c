uint32_t reverseBits(uint32_t n) {
    uint32_t ret_val = 0;
    uint32_t _1_bits[32] = {0};
    int index = 0;
    while (n) {
        if ((1 & n) == 1) {
            _1_bits[index] = 1;
        }
        index++;
        n >>= 1;
    }

    index--;

    while (index >= 0) {
        ret_val += _1_bits[index] << (31-index);
        index--;
    }

    return ret_val;
}