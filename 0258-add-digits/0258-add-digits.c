int addDigits(int num) {
    int ret_num = 0;
    while (num/10 || ret_num != 0) {
        ret_num += num % 10;
        num /= 10;
        if (num == 0) {
            num = ret_num;
            ret_num = 0;
        }
    }
    return num;
}