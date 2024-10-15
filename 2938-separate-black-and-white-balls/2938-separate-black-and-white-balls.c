void swap(char *str_1, char *str_2) {
    char tmp = *str_1;
    *str_1 = *str_2;
    *str_2 = tmp;
}

long long minimumSteps(char* s) {
    // count how much steps to move all 1 to right side.
    long long steps = 0;
    int str_len_s = strlen(s);  // 3
    int rightest_zero_position[100000];
    int count_zero = -1;
    int count_zero_head = 0;
    int size = 0;
    int i = str_len_s-1;
    while (i >= 0) {
        //printf("s[%d] = %c.\n", i, s[i]);
        // recording the pointer to the rightest 0.
        if (s[i] == '1') {      //
            // check if count == -1, if not swap 1 and 0.
            if (size != 0) {
                steps += (rightest_zero_position[count_zero_head] - i);
                //printf("swap %d %d.\n", i, rightest_zero_position[count_zero]);
                swap(s + i, s + rightest_zero_position[count_zero_head++]);
                // record this index into heap.
                rightest_zero_position[++count_zero] = i;
            }
        } else if (s[i] == '0'){
            // record its index;
            rightest_zero_position[++count_zero] = i;
            size++;
        }
        i--;
    }
    return steps;
}