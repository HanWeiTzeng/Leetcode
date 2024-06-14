char* smallestNumber(char* pattern) {
    int number = strlen(pattern);
    // use 2 index to put value;
    char *ret_array = (char *) malloc(sizeof(char)*(number+2));
    int stack[number+1];
    int i = 0;
    int top = -1;
    int count = 1;
    while (pattern[i] != '\0') {
        if (pattern[i] == 'I' && top == -1) {
            ret_array[i] = count +'0';
            count++;
        } else if (pattern[i] == 'I' && top != -1) {
            ret_array[i] = count +'0';
            count++;
            while (top != -1) {
                ret_array[stack[top]] = count + '0';
                //printf("1 top = %d", top);
                //printf("ret_array[%d] = %d\n ", stack[top], count);
                count++;
                top--;
            }
        } else if (pattern[i] == 'D') {
            stack[++top] = i;  // 3
        }
        i++;
    }
    stack[++top] = i;  // 3
    while (top != -1) {
        ret_array[stack[top]] = count + '0';
        //printf("2 top = %d, i = %d", top, i);
        //printf("ret_array[%d] = %d\n ", stack[top], count);
        count++;
        top--;
        i++;
    }
    ret_array[number+1] = '\0';
    return ret_array;
}