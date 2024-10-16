char* longestDiverseString(int a, int b, int c) {
    char *ret_str = (char *) malloc(sizeof(char)* (a + b + c + 2));
    // check which one is largest
    // need a variable to count contineous times.
    int count = 0;
    char current_letter = 'd';
    int total = 0;
    // first 2 should be most
    while (a > 0 && b > 0 || a > 0 && c > 0 || b > 0 && c > 0) {
        //printf("cur_le %c %d %d %d.\n", current_letter, a, b, c);
        if (a >= b && a >= c) {
            while (count < 2 && a > 0) {
                if (current_letter == 'a')
                    count++;
                else {
                    count = 0;
                }
                current_letter = 'a';
                a--;
                ret_str[total++] = 'a';
                count++;
            }
            count = 0;
            if (b >= c) {
                current_letter = 'b';
                ret_str[total++] = 'b';
                b--;
                count++;
            } else if (c > b){
                current_letter = 'c';
                ret_str[total++] = 'c';
                c--;
                count++;
            }
        } else if (b >= a && b >= c) {
            while (count < 2 && b > 0) {
                if (current_letter == 'b')
                    count++;
                else {
                    count = 0;
                }
                b--;
                ret_str[total++] = 'b';
                count++;
                current_letter = 'b';
            }
            count = 0;
            if (a >= c) {
                current_letter = 'a';
                ret_str[total++] = 'a';
                count++;
                a--;
            } else if (c > a){
                current_letter = 'c';
                ret_str[total++] = 'c';
                count++;
                c--;
            }
        } else if (c >= a && c >= b) {
            while (count < 2 && c > 0) {
                if (current_letter == 'c')
                    count++;
                else {
                    count = 0;
                }
                c--;
                ret_str[total++] = 'c';
                count++;
                current_letter = 'c';
            }
            count = 0;
            if (a >= b) {
                current_letter = 'a';
                ret_str[total++] = 'a';
                count++;
                a--;
            } else if (b > a){
                current_letter = 'b';
                ret_str[total++] = 'b';
                count++;
                b--;
            }
        }
    }

    while (count < 2 && a > 0) {
        if (current_letter == 'a')
            count++;
        else {
            count = 0;
        }
        current_letter = 'a';
        a--;
        ret_str[total++] = 'a';
        count++;
    }

    while (b > 0 && count < 2) {
        if (current_letter == 'b')
            count++;
        else {
            count = 0;
        }
        current_letter = 'b';
        b--;
        ret_str[total++] = 'b';
        count++;
    }
    
    while (c > 0 && count < 2) {
        if (current_letter == 'c')
            count++;
        else {
            count = 0;
        }
        current_letter = 'c';
        c--;
        ret_str[total++] = 'c';
        count++;
    }
    
    ret_str[total] = '\0';
    return ret_str;
}