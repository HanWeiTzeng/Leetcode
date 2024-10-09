int minAddToMakeValid(char* s) {
    char stack[1000];
    int stack_idx = -1;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == ')') {
            // check if (stack[stack_idx])
            if (stack_idx != -1 && stack[stack_idx] == '(') {
                stack_idx--;
            } else {
                stack[++stack_idx] = ')';
            }
        } else {    // if s[i] == '('
            stack[++stack_idx] = '(';
        }
        i++;
    }

    return stack_idx+1;
}