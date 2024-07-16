char* addBinary(char* a, char* b) {
    int str_len_a = strlen(a);
    int str_len_b = strlen(b);
    int max_str_len = fmax(str_len_a, str_len_b);
    char *ret_str = (char *) malloc(sizeof(char)*(max_str_len+2));
    int carry = 0;
    int index_a = str_len_a-1;
    int index_b = str_len_b-1;
    int index_c = 0;
    while (index_a >= 0 && index_b >= 0) {
        if (a[index_a] == '1' && b[index_b] == '1' && carry == 1) {
            ret_str[index_c++] = '1';
        } else if (a[index_a] == '1' && b[index_b] == '1' && carry == 0) {
            carry = 1;
            ret_str[index_c++] = '0';
        } else if (a[index_a] == '1' && b[index_b] == '0' && carry == 1) {
            ret_str[index_c++] = '0';
        } else if (a[index_a] == '0' && b[index_b] == '1' && carry == 1) {
            ret_str[index_c++] = '0';
        } else if (a[index_a] == '0' && b[index_b] == '1' && carry == 0) {
            ret_str[index_c++] = '1';
        } else if (a[index_a] == '1' && b[index_b] == '0' && carry == 0) {
            ret_str[index_c++] = '1';
        } else if (a[index_a] == '0' && b[index_b] == '0' && carry == 0) {
            ret_str[index_c++] = '0';
        } else if (a[index_a] == '0' && b[index_b] == '0' && carry == 1) {
            carry = 0;
            ret_str[index_c++] = '1';
        }
        index_a--;
        index_b--;
    }
    while (index_b >= 0) {
        if (b[index_b] == '1' && carry == 1) {
            ret_str[index_c++] = '0';
        } else if (b[index_b] == '1' && carry == 0) {
            ret_str[index_c++] = '1';
        } else if (b[index_b] == '0' && carry == 1) {
            ret_str[index_c++] = '1';
            carry = 0;
        } else if (b[index_b] == '0' && carry == 0) {
            ret_str[index_c++] = '0';
        }
        index_b--;
    }
    while (index_a >= 0) {
        if (a[index_a] == '1' && carry == 1) {
            ret_str[index_c++] = '0';
        } else if (a[index_a] == '1' && carry == 0) {
            ret_str[index_c++] = '1';
        } else if (a[index_a] == '0' && carry == 1) {
            ret_str[index_c++] = '1';
            carry = 0;
        } else if (a[index_a] == '0' && carry == 0) {
            ret_str[index_c++] = '0';
        }
        index_a--;
    }
    if (carry == 1) {
        ret_str[index_c++] = '1';
    }
    printf("%s", ret_str);
    for (int i = 0; i < index_c/2; i++) {
        char tmp = ret_str[i];
        ret_str[i] = ret_str[index_c-1-i];
        ret_str[index_c-1-i] = tmp;
    }
    ret_str[index_c] = '\0';
    printf("%s", ret_str);
    return ret_str;
}