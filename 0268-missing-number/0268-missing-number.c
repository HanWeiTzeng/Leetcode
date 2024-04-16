//有四種方法，全部都要會!!


/*Hashtable*/

struct hashtable {
    int key;
    UT_hash_handle hh;
};

int missingNumber(int* nums, int numsSize) {
    struct hashtable *ref = NULL;
    struct hashtable *tmp;

    for (int i = 0; i < numsSize; i++) {
        tmp = malloc(sizeof(struct hashtable));
        tmp->key = nums[i];
        HASH_ADD_INT(ref, key, tmp);
    }

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(ref, &i, tmp);
        if (tmp == NULL) {
            return i;
        }
    }
    return numsSize;
}

// ======================================
/* 快速排列 quick sort*/
/*
int cmp(const void *e1, const void *e2) {
    return *(int*)e1 - *(int*)e2; 
}
int missingNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i) return i;
    }
    return numsSize;
}
===============================
*/
/* 利用總和差
int missingNumber(int* nums, int numsSize) {
    int count = numsSize;
    for (int i = 0; i < numsSize; i++) {
        count += i - nums[i];
    }
    return count;
}
*/
/*
===========================================
/* selection sort 
int missingNumber(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int min = nums[i];
        int min_idx = i;
        for (int j = i+1; j < numsSize; j++) {
            if (nums[j] < min) {
                min = nums[j];
                min_idx = j;
            }
        }
        if (min != i) return i;
            else {
                int tmp = nums[i];
                nums[i] = min;
                nums[min_idx] = tmp;
            }
    }
    return numsSize;
}

========================================
/* 全部排序 bubble sort
int missingNumber(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    int i = 0;
    while (i < numsSize && nums[i] == i) {
        i++;
    }
    return i;
}
*/
