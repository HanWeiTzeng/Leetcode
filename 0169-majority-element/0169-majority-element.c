//    哈希表可以用...

//    異同互殺法:

int majorityElement(int* nums, int numsSize) {
    int most_num = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            most_num = nums[i];
            count++;
        } else if (most_num != nums[i]) {
            count--;
        } else {
            count++;
        }
    }
    return most_num;
}

/*
=============================
Quick sort法+ return nums[numsSize/2]

int cmp(const void *e1, const void *e2) { =====> 更簡潔
      return *(int*)e1 - *(int*)e2;
}

int compare(const void *a, const void *b) {
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}               //傳回 -1 代表 a < b
      else if (c == d) {return 0;}      //傳回   0 代表 a = b
      else return 1;                          //傳回  1 代表 a>b
}


int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    return nums[numsSize/2];
}
*/