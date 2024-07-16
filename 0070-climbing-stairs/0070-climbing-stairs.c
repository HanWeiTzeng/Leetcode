int climbStairs(int n) {
    // n = 1 return 1;
    // n = 2 return 2;
    // n = 3 return 3;
    // n = 4 return 5;
    // n = 5 return 8;
    if (n == 1 || n == 2)
        return n;

    int count1 = 2;
    int count2 = 1;
    for (int i = 2; i < n; i++) {
        int tmp = count2;   // tmp = 1 2
        count2 = count1;    // count2 = 2 3
        count1 = count1 + tmp;  // count1 = 3 5
    }
    return count1;
}