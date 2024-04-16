int climbStairs(int n) {
    int n1 = 1;
    int n2 = 2;
    for (int i = 3; i <= n; i++) {
        if (i % 2 == 1) n1 = n1 + n2;
        else  n2 = n1 + n2;
    }
    if (n % 2 == 1)
        return n1;
    else 
        return n2;
}

 // Runtime Error !: Recursive:
/*
int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return climbStairs(n-1) + climbStairs(n-2);
}
*/