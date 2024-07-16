char* intToRoman(int num) {
    char* ret_str = (char*)malloc(sizeof(char) * 20);
    int index = 0;
    int nums[4] = {0};

    while (num != 0) {
        nums[index++] = num % 10; // 9473
        num /= 10;
    }
    index--;
    int i = 0;

    while (index >= 0) {
        if (index == 3) {
            while (nums[index] > 0) {
                ret_str[i++] = 'M';
                nums[index]--;
            }
        } else if (index == 2) {
            if (nums[index] == 9) {
                ret_str[i++] = 'C';
                ret_str[i++] = 'M';
            } else if (nums[index] == 4) {
                ret_str[i++] = 'C';
                ret_str[i++] = 'D';
            } else if (nums[index] < 4) {
                while (nums[index] > 0) {
                    ret_str[i++] = 'C';
                    nums[index]--;
                }
            } else if (nums[index] < 9) {
                ret_str[i++] = 'D';
                while (nums[index] > 5) {
                    ret_str[i++] = 'C';
                    nums[index]--;
                }
            }
        } else if (index == 1) {
            if (nums[index] == 9) {
                ret_str[i++] = 'X';
                ret_str[i++] = 'C';
            } else if (nums[index] == 4) {
                ret_str[i++] = 'X';
                ret_str[i++] = 'L';
            } else if (nums[index] < 4) {
                while (nums[index] > 0) {
                    ret_str[i++] = 'X';
                    nums[index]--;
                }
            } else if (nums[index] < 9) {
                ret_str[i++] = 'L';
                while (nums[index] > 5) {
                    ret_str[i++] = 'X';
                    nums[index]--;
                }
            }
        } else if (index == 0) {
            if (nums[index] == 9) {
                ret_str[i++] = 'I';
                ret_str[i++] = 'X';
            } else if (nums[index] == 4) {
                ret_str[i++] = 'I';
                ret_str[i++] = 'V';
            } else if (nums[index] < 4) {
                while (nums[index] > 0) {
                    ret_str[i++] = 'I';
                    nums[index]--;
                }
            } else if (nums[index] < 9) {
                ret_str[i++] = 'V';
                while (nums[index] > 5) {
                    ret_str[i++] = 'I';
                    nums[index]--;
                }
            }
        }
            index--;
        }
        ret_str[i] = '\0';
        return ret_str;
    }