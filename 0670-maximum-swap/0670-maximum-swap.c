void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int maximumSwap(int num) {
    int *arr = (int *) malloc(sizeof(int) * 8);
    int arr_size = 0;
    int ori_num = num;
    while (ori_num != 0) {
        arr[arr_size++] = ori_num % 10;
        ori_num /= 10;
        printf("arr[%d] = %d.\n", arr_size-1, arr[arr_size-1]);
    }
    // find the max value.
    int max = arr[arr_size-1];
    int target_max_idx = arr_size-1;
    int idx = arr_size-1;
    while (idx != -1) {
        for (int i = idx-1; i >= 0; i--) {
            //printf("max = %d, idx = %d.\n", max, idx);
            if (max < arr[i]) {
                //printf("max changed into arr[%d] %d.\n", i, arr[i]);
                max = arr[i];
                target_max_idx = i;
            } else if (max == arr[i] && target_max_idx != idx) {
                max = arr[i];
                target_max_idx = i;
            }
        }
        // if idx == target_max.
        if (idx == target_max_idx) {
            idx--;
            target_max_idx--;
            if (idx >= 0)
                max = arr[idx];
        } else {
            swap(arr + target_max_idx, arr + idx);
            for (int i = arr_size -1 ; i >= 0; i--) {
                ori_num *= 10;
                ori_num += arr[i];
                //printf("arr[%d] = %d. ori_num %d\n", i, arr[i], ori_num);
            }
            //printf("ori_num = %d.\n", ori_num);
            return ori_num;
        }
    }
    return num;
}