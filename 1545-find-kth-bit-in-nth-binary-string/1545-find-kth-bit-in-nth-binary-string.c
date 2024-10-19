char *inverse_str(char *target_str, int *total_element) {
    char *reverse_str = (char *) malloc(sizeof(char) * (*total_element+1));
    if (!reverse_str) {
        printf("failed.\n");
        return NULL;
    }
    int count = *total_element -1 ;
    int reverse_str_idx = 0;
    while (count >= 0) {
        if (target_str[count] == '1') {
            reverse_str[reverse_str_idx] = '0';
        } else if (target_str[count] == '0') {
            reverse_str[reverse_str_idx] = '1';
        }
        reverse_str_idx++;
        count--;
    }
    reverse_str[reverse_str_idx] = '\0';
    return reverse_str;
}


void sub_function(char *target_str, int n, int *total_element) {
    if (n > 1) {
        char *reverse_str = inverse_str(target_str, total_element);
        // add one in middle
        strcat(target_str, "1");
        // add reversed_string just after string.
        strcat(target_str, reverse_str);
        //printf("After %s.\n", target_str);
        *total_element *= 2;
        *total_element += 1;
        sub_function(target_str, n-1, total_element);
    }
}


char findKthBit(int n, int k) {
    int str_size = 0;
    for (int i = 0; i < n; i++) {
        str_size *= 2;
        str_size += 1;
    }
    char *target_str = (char *)malloc(sizeof(char *) * str_size);
    // first few element is the same
    int total_element = 1;
    target_str[total_element-1] = '0';
    target_str[total_element] = '\0';
    sub_function(target_str, n, &total_element);
    //printf("total_element %d ", total_element);
    char ret_char = target_str[k-1]; 
    return ret_char;
}