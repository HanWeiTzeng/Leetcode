int cmp(const void *e1, const void *e2) {
    return *(int *)e1 - *(int *)e2;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize-1; i++) {
        if (nums[i] == nums[i+1]) return true;
    }
    return false;
}
/*
===============================
Hash table 哈希表
pseudo code:
創一個hash table *variable = NULL
用HASH_FIND_INT去 find 他 
HASH_FIND_INT(set, nums + i, tmp);  // num[i] 要用& num[i]去傳
所以= & * (nums+i) = nums+i

沒找到會是return NULL
有找到就不是NULL->此時直接return true;
沒找到就要補上:用HASH_ADD_INT去補 key: (注意此處key的使用方式是key)
tmp = malloc(sizeof(struct hashTable));
tmp->key = nums[i];
HASH_ADD_INT(set, key, tmp);
你做得到~


struct hashTable {
    int key;
    UT_hash_handle hh;
};

bool containsDuplicate(int* nums, int numsSize) {
    struct hashTable* set = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* tmp;		         ///tmp不用=NULL
        HASH_FIND_INT(set, nums + i, tmp);         ///此時tmp沒有空間
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct hashTable));     ///此時tmp給空間
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);
        } else {
            return true;
        }
    }
    return false;
}

作者：力扣官方题解
链接：https://leetcode.cn/problems/contains-duplicate/solutions/518991/cun-zai-zhong-fu-yuan-su-by-leetcode-sol-iedd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处
*/