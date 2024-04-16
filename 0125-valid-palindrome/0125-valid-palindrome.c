// 回文（順讀和倒讀都一樣的詞、詩句等）
// 看PC上寫的方式

bool isPalindrome(char* s) {
    int strlen_s = strlen(s);
    if (strlen_s <= 1) return true;
    int i = 0, j = strlen_s-1;
    char a = '\0', b = '\0';
    while (i <= j) {
        if (a == '\0') {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                a = s[i]-'A'+'a'; 
            } else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
                a = s[i];
            }
            i++;
        } else if (b == '\0') {
            if (s[j] >= 'A' && s[j] <= 'Z') {
                b = s[j]-'A'+'a'; 
            } else if (s[j] >= 'a' && s[j] <= 'z' || s[j] >= '0' && s[j] <= '9') {
                b = s[j];
            }
            j--;
        }
        if (a != '\0' && b != '\0' && a != b) {
            return false;
        }
        else if (a != '\0' && b != '\0' && a == b){
            a = '\0';
            b = '\0';
        }
    }
    return true;
}