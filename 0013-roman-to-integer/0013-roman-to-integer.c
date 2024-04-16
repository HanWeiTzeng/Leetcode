//  三種做法:
//  1. 900/400 直觀
//  2. +100 then 1000-200/ +100 then 500-200
//  3. 用前面 >後面 去算

int romanToInt(char* s) {
    int i = 0;
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case 'I':
                if (i < strlen(s)-1 && s[i+1] == 'V') {
                    count += 4;
                    i++;
                } else if (i < strlen(s)-1 && s[i+1] == 'X') {
                    count += 9;
                    i++;
                } else {
                    count += 1;
                }
                break;
            case 'V':
                count += 5;
                break;
            case 'X':
                if (i < strlen(s)-1 && s[i+1] == 'L') {
                    count += 40;
                    i++;
                } else if (i < strlen(s)-1 && s[i+1] == 'C') {
                    count += 90;
                    i++;
                } else {
                    count += 10;
                }
                break;
            case 'L':
                count += 50;
                break;
            case 'C':
                if (i < strlen(s)-1 && s[i+1] == 'D') {
                    count += 400;
                    i++;
                } else if (i < strlen(s)-1 && s[i+1] == 'M') {
                    count += 900;
                    i++;
                } else {
                    count += 100;
                }
                break;
            case 'D':
                count += 500;
                break;
            case 'M':
                count += 1000;
                break;
        }
    }
    return count;
}

/* int romanToInt(char* s) {
    int i = 0;
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case 'I':
                count += 1;
                break;
            case 'V':
                count += 5;
                if (i > 0 && s[i-1] == 'I') {
                   count -= 2; 
                }
                break;
            case 'X':
                count += 10;
                if (i > 0 && s[i-1] == 'I') {
                   count -= 2; 
                }
                break;
            case 'L':
                count += 50;
                if (i > 0 && s[i-1] == 'X') {
                   count -= 20; 
                }
                break;
            case 'C':
                count += 100;
                if (i > 0 && s[i-1] == 'X') {
                   count -= 20; 
                }
                break;
            case 'D':
                count += 500;
                if (i > 0 && s[i-1] == 'C') {
                   count -= 200; 
                }
                break;
            case 'M':
                count += 1000;
                if (i > 0 && s[i-1] == 'C') {
                   count -= 200; 
                }
                break;
        }
    }
    return count;
}
*/