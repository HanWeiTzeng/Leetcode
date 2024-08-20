int evalRPN(char** tokens, int tokensSize) {
    // create a stack
    int *num_stack = (int *) malloc(sizeof(int) * tokensSize);
    int total = 0, tmp1 = 0, tmp2 = 0, index = 0, flag = 0;
    for (int i = 0; i < tokensSize; i++) {
        //char a = (char)tokens[i][0];
        int nums = atoi(tokens[i]);
        if (nums == 0) {
            switch(tokens[i][0]) {
                // when encounter sign -> pop out 2. then add to total.
                case '+':
                    tmp2 = num_stack[--index];
                    tmp1 = num_stack[--index];
                    total = tmp1 + tmp2; // 2 + 1
                    printf("%d + %d.\n", tmp2, tmp1);
                    num_stack[index++] = total;
                    break;
                case '-':
                    tmp2 = num_stack[--index];
                    tmp1 = num_stack[--index];
                    total = tmp1 - tmp2; // 2 + 1
                    printf("%d - %d.\n", tmp2, tmp1);
                    num_stack[index++] = total;
                    break;
                case '*':
                    tmp2 = num_stack[--index];
                    tmp1 = num_stack[--index];
                    total = tmp1 * tmp2; // 2 + 1
                    printf("%d * %d.\n", tmp2, tmp1);
                    num_stack[index++] = total;
                    break;
                case '/':
                    tmp2 = num_stack[--index];
                    tmp1 = num_stack[--index];
                    total = tmp1 / tmp2; // 2 + 1
                    printf("%d / %d.\n", tmp2, tmp1);
                    num_stack[index++] = total;
                    break;
                // when encounter numbers -> store.
                default:
                    num_stack[index++] = atoi(tokens[i]);
            }
        } else {
            num_stack[index++] = atoi(tokens[i]);
        }
        printf("total = %d.\n", total);
    }
    // return total.
    if (flag == 0)
        total = num_stack[--index];
    return total;
}