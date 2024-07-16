bool isValid(char* s) {
    // create a stack, put ([{ and pop it when hit )]}
    int str_len_s = strlen(s);
    if (str_len_s % 2 == 1) {
        return false;
    }
    int *stack_s = (int *)malloc(sizeof(int) * str_len_s);
    int i = 0;
    int j = 0;
    while (i < str_len_s) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack_s[j++] = s[i];
        } else {
            if (j <= 0) {
                free(stack_s);
                return false;
            }
            if (s[i] == ')') {
                if (stack_s[j-1] == '(') {
                    j--;
                } else {
                    free(stack_s);
                    return false;
                }
            } else if (s[i] == ']') {
                if (stack_s[j-1] == '[') {
                    j--;
                } else {
                    free(stack_s);
                    return false;
                }
            } else if (s[i] == '}') {
                if (stack_s[j-1] == '{') {
                    j--;
                } else {
                    free(stack_s);
                    return false;
                }
            }
        }
        i++;
    }
    free(stack_s);
    if (j != 0) {
        return false;
    }
    return true;
}