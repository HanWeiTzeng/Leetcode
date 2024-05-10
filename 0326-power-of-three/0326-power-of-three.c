bool isPowerOfThree(int n) {
    if (n == 1) return true;
        else if (n == 0) return false;
    if ((n/3)*3 == n) return isPowerOfThree(n/3);
    else return false;
}