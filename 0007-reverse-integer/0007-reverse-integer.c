int reverse(int x){
    // check if it is +/-,
    int i = 0;
    int *digital = (int *)malloc(sizeof(int)*12);
    int ret_val = 0;
    //int positive = 1;
    //if (x < 0) positive = 0;

    // divide 1/10 keep
    while (x != 0) {
        digital[i++] = x%10;    //  3
        //printf(" digital[%d++] = %d.\n",i-1,  digital[i-1]);
        x = x/10;   // 12
    }
    // record 位數
    int count = 0;
    // check 0
    while (count < i) {
        if (ret_val > 0 && ret_val > INT_MAX/10 || ret_val < 0 && ret_val < INT_MIN/10) {
            //printf("Enter.\n");
            ret_val = 0;
            count = i;
        } else {
            ret_val *= 10;
            ret_val += digital[count++];
        }
    }
    //if (positive == 0) ret_val = -ret_val;
    return ret_val;
}