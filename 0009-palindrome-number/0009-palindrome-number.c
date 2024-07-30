bool isPalindrome(int x) {
    if (x < 0)
        return false;
    // measure the length of x.

    int len_x = 0;
    int runner = x;
    while (runner != 0) {
        runner /= 10;
        len_x++;
    }

    int flag = 0;
    if (len_x % 2 == 1)
        flag = 1;

    len_x /= 2; // aware odd and even.
    int check_val = 0;

    while (len_x != 0) {
        check_val *= 10;
        check_val += x % 10;
        x /= 10;
        len_x--;
    }
    if (flag == 1) {
        check_val *= 10;
        check_val += x % 10;
    }

    if (check_val == x) {
        return true;
    }

    return false;
}