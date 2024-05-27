/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(void *a, void *b, size_t size) {
    unsigned char *p = a;
    unsigned char *q = b;
    unsigned char tmp;
    for (size_t i = 0; i < size; ++i) {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

int partition(int *nums, int left, int right, char** names) {
    int pivot = nums[right];
    int i = left;
    int j = right -1;
    while (i < j) {
        while (i < right && nums[i] > pivot) i++;
        while (j > left && nums[j] < pivot) j--;
        if (i < j) {
            swap(&nums[i], &nums[j], sizeof(int));
            swap(&names[i], &names[j], sizeof(char*));
        }
    }
    if (nums[i] < pivot) {
        swap(&nums[i], &nums[right], sizeof(int));
        swap(&names[i], &names[right], sizeof(char*));
    }
    return i;
}

void quicksort(int *nums, int left, int right, char** names) {
    if (left < right) {
        int partition_pos;
        partition_pos = partition(nums, left, right, names);
        quicksort(nums, left, partition_pos-1, names);
        quicksort(nums, partition_pos+1, right, names);
    }
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    *returnSize = namesSize;
    char **ret_names = (char **) malloc (sizeof(char*)* *returnSize);
    // quick sort with height and names.
    for (int i = 0; i < namesSize; i++) {
        ret_names[i] = (char *) malloc(sizeof(char)*(strlen(names[i])+1));
        strcpy(ret_names[i], names[i]);
    }
    quicksort(heights, 0, heightsSize-1, ret_names);
    return ret_names;
}