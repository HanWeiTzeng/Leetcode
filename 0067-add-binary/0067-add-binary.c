//  1. 這題也可以用轉換成10進位，加完再換回來
//  2. 直接 char + carry到底:

void reverse(char* s) {
    int s_len = strlen(s);
    for(int i = 0; i < s_len/2; i++) {      // Remeber: reverse just need to run half of string.
        char t = s[i];
        s[i] = s[s_len-1-i];
        s[s_len-1-i] = t;
    }
}

char* addBinary(char* a, char* b) {
    char* c;
    int a_len = strlen(a);
    int b_len = strlen(b);
    int len = fmax(a_len , b_len);
    int carry = 0;
    c = (char *)malloc(sizeof(char)*(len+2));
    reverse(a);
    reverse(b);
    for (int i = 0; i < len; i++) {
        (i < a_len) ? carry += (a[i] == '1') : 0;
        (i < b_len) ? carry += (b[i] == '1') : 0;
        c[i] = '0' + carry % 2;    // since it's binary logical.
        					//printf("a= %c b = %c c = %c %d",a[i], b[i], c[i], i);
        					//printf("carry = %d \n", carry);
        carry /= 2;
    }
    					//printf("carry = %d", carry);
    if (carry) {
        c[len++] = '1';
    }
    c[len] = '\0';
    reverse(c);
    return c;
}
    