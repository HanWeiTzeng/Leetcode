int singleNumber(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        count ^= nums[i];
    }
    return count;
}


/* Hash table method
struct hashtable{
    int key;
    int count;
    UT_hash_handle hh;
};

int singleNumber(int* nums, int numsSize) {
    struct hashtable *ref = NULL;
    struct hashtable *tmp;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(ref, nums+i, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct hashtable));
            tmp->key = nums[i];
            tmp->count = 1;
            HASH_ADD_INT(ref, key, tmp);
        } else {
            tmp->count++;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(ref, nums + i, tmp);
        if (tmp->count == 1) return tmp->key;
    }
    return -1;
}
*/