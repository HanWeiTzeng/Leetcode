int romanToInt(char* s) {
    // get length of string.
    int str_len = strlen(s);
    int index = 0;
    int total = 0;

    // distinguish I II III IV V VI VII VIII IX X
    // deal with it and start from M
    //while (index < str_len) {
    for (index = 0; index < str_len; index++) {
        switch(s[index]) {
            case 'M':
                total += 1000;
                break;
            case 'D':
                total += 500;
                break;
            case 'C':
                total += 100;
                if (index+1 < str_len) {
                    if (s[index+1] == 'D') {
                        total = total - 200 + 500;
                        index++;
                    } else if (s[index+1] == 'M') {
                        total = total - 200 + 1000;
                        index++;
                    }
                }
                break;
            case 'L':
                total += 50;
                break;
            case 'X':
                total += 10;
                if (index+1 < str_len) {
                    if (s[index+1] == 'L') {
                        total = total - 20 + 50;
                        index++;
                    } else if (s[index+1] == 'C') {
                        total = total - 20 + 100;
                        index++;
                    }
                }
                break;
            case 'V':
                total += 5;
                break;
            case 'I':
                total += 1;
                if (index+1 < str_len) {
                    if (s[index+1] == 'V') {
                        total = total - 2 + 5;
                        index++;
                    } else if (s[index+1] == 'X') {
                        total = total - 2 + 10;
                        index++;
                    }
                }
                break;
        }
        //index++;
    }

    return total;
}