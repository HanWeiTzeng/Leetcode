char pair(char br) {
    if (br == '}') return '{';
    if (br == ')') return '(';
    if (br == ']') return '[';
    return '\0';
}

bool isValid(char* s) {
    int i = 0;
    int j = 0;
    char stack_b[strlen(s)/2+1];
    while (i < strlen(s)) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {     // {[( store in stack_b
            stack_b[j++] = s[i];
            if (j > strlen(s)/2) return false;
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') { // )]} change to {[( and check 
            if (j == 0) return false;
            if (stack_b[j-1] == pair(s[i])) {
                j--;
            } else {
                return false;
            }
        } else return false;
        i++;
    }
    if (j == 0 && i == strlen(s)) return true;
    else return false;
}