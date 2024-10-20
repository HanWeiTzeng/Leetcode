bool parseBoolExpr(char* expression) {
    // need to identify last '('
    // record the current status t/f
    // use the ) to count how much operations need to calculate. 
    int operations_count = 0;
    int expression_str_len = strlen(expression);
    int left_brackets_idx_stk[expression_str_len/2];
    int left_brackets_count = 0;
    int right_brackets_idx_stk[expression_str_len/2][2];
    int right_brackets_count = 0;
    
    // 右括號
    for (int i = 0; i < expression_str_len; i++) {
        if (expression[i] == ')') {
            operations_count++;
            right_brackets_idx_stk[right_brackets_count][0] = i;
            right_brackets_idx_stk[right_brackets_count][1] = 0;    // have not be used.
            right_brackets_count++;
        }
        if (expression[expression_str_len - i] == '(') {
            left_brackets_idx_stk[left_brackets_count++] = expression_str_len - i;
        }
    }

    bool current_status;

    int left_stk_idx = 0;
    int right_stk_idx = 0;
    char operator;
    int k = operations_count;
    while (k > 0) {
        //printf("k = %d.\n", k);
        // use two pointers to run.
        // check
        right_stk_idx = 0;
        // TBD.
        int i = right_brackets_idx_stk[right_stk_idx][0];
        while (right_brackets_idx_stk[right_stk_idx][1] == 1 || i < left_brackets_idx_stk[left_stk_idx]) {
            right_stk_idx++;
            i = right_brackets_idx_stk[right_stk_idx][0];  // 右括號位置
            //printf("expression[%d] = %c.\n", i, expression[i]);
        }
        //printf("Final right position is %d.\n", i);
        right_brackets_idx_stk[right_stk_idx][1] = 1;

        // find which operator will be used.
        int j = 1;
        int flag = 0;

        switch(expression[left_brackets_idx_stk[left_stk_idx]-1]) {
            case '&':
                expression[left_brackets_idx_stk[left_stk_idx]-1] = ',';    // '&' -> ','
                expression[left_brackets_idx_stk[left_stk_idx]] = ',';      // '(' -> ','
                // 從左算到右
                while (left_brackets_idx_stk[left_stk_idx] + j < i) {
                    if (expression[left_brackets_idx_stk[left_stk_idx] + j] == 't') {
                        if (flag == 0) {
                            current_status = true;
                            flag = 1;
                        }
                        expression[left_brackets_idx_stk[left_stk_idx] + j] = ',';
                        //printf("&t// %B.\n", current_status);
                        current_status &= true;
                    } else if (expression[left_brackets_idx_stk[left_stk_idx] + j] == 'f' ) {
                        if (flag == 0) {
                            current_status = false;
                            flag = 1;
                        }
                        expression[left_brackets_idx_stk[left_stk_idx] + j] = ',';
                        //printf("&f// %B.\n", current_status);
                        current_status &= false;
                    }
                    j++;
                }
                flag = 0;
                if (current_status == true) {
                    expression[left_brackets_idx_stk[left_stk_idx] + j] = 't';
                } else {
                    expression[left_brackets_idx_stk[left_stk_idx] + j] = 'f';
                }
                //printf("&// %s", expression);
                break;
            case '|':
                expression[left_brackets_idx_stk[left_stk_idx]-1] = ',';    // '|' -> ','
                expression[left_brackets_idx_stk[left_stk_idx]] = ',';      // '(' -> ','
                // 從左算到右
                while (left_brackets_idx_stk[left_stk_idx] + j < i) {
                    //printf("%d < %d.\n",left_brackets_idx_stk[left_stk_idx] + j, i);
                    if (expression[left_brackets_idx_stk[left_stk_idx] + j] == 't') {
                        if (flag == 0) {
                            current_status = true;
                            flag = 1;
                        }
                        expression[left_brackets_idx_stk[left_stk_idx] + j] = ',';
                        current_status |= true;
                        //printf("%B |// true.\n", current_status);
                    } else if (expression[left_brackets_idx_stk[left_stk_idx] + j] == 'f') {
                        if (flag == 0) {
                            current_status = false;
                            flag = 1;
                        }
                        expression[left_brackets_idx_stk[left_stk_idx] + j] = ',';
                        current_status |= false;
                        //printf("%B |// false.\n", current_status);
                    }
                    j++;
                }
                flag = 0;
                //printf("result |// %B.\n", current_status);
                if (current_status == true) {
                    expression[left_brackets_idx_stk[left_stk_idx] + j] = 't';
                } else {
                    expression[left_brackets_idx_stk[left_stk_idx] + j] = 'f';
                }
                //printf("|// %s", expression);
                break;
            case '!':
                expression[left_brackets_idx_stk[left_stk_idx]-1] = ',';    // '!' -> ','
                //printf("! %B.\n", current_status);
                expression[left_brackets_idx_stk[left_stk_idx]] = ',';      // '(' -> ','
                while (left_brackets_idx_stk[left_stk_idx] + j < i) {
                    if (expression[left_brackets_idx_stk[left_stk_idx] + j] == 't') {
                        if (flag == 0) {
                            current_status = true;
                            flag = 1;
                        }
                        expression[left_brackets_idx_stk[left_stk_idx] + j] = ',';
                        current_status = !(current_status);
                        //printf("%B // true become false.\n", current_status);
                    } else if (expression[left_brackets_idx_stk[left_stk_idx] + j] == 'f') {
                        if (flag == 0) {
                            current_status = false;
                            flag = 1;
                        }
                        expression[left_brackets_idx_stk[left_stk_idx] + j] = ',';
                        current_status = !(current_status);
                        //printf("%B |// false become true.\n", current_status);
                    }
                    j++;
                }
                flag = 0;
                if (current_status == true) {
                    expression[left_brackets_idx_stk[left_stk_idx] + j] = 't';
                } else {
                    expression[left_brackets_idx_stk[left_stk_idx] + j] = 'f';
                }
                //printf("!// %s", expression);
                break;
        }
        left_stk_idx++;
        k--;
    }
    return current_status;
}