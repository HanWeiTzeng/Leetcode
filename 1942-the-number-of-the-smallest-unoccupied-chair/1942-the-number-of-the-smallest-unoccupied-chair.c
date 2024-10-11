// Comparison function to sort by enter time (friend_etr_lev_order[i][1])
int compare(const void* a, const void* b) {
    const int* rowA = (const int*)a;
    const int* rowB = (const int*)b;
    // Compare enter times (the second element of each row)
    return rowA[1] - rowB[1];
}

int smallestChair(int** times, int timesSize, int* timesColSize, int targetFriend) {

    // create a table to implement.
    int friend_etr_lev_order[timesSize][3];
    for (int i = 0; i < timesSize; i++) {
        friend_etr_lev_order[i][0] = i;               // friend ID.
        friend_etr_lev_order[i][1] = times[i][0];     // enter time.
        friend_etr_lev_order[i][2] = times[i][1];     // leave time.
    }
    // sorting them.
    qsort(friend_etr_lev_order, timesSize, sizeof(friend_etr_lev_order[0]), compare);
    for (int i = 0; i < timesSize; i++) {
        printf("#%d entering:%d leaving:%d.\n",friend_etr_lev_order[i][0], friend_etr_lev_order[i][1],friend_etr_lev_order[i][2]);
    }
    // check who has entered the table, and check if they are leaved.
    int table_queue[timesSize][3];
    int i = 0, total = 0, flag , flag_target_friend_entered = 0;
    printf("Enter time: %d.\n", times[targetFriend][0]);
    while (flag_target_friend_entered != 1) {
        printf("friend %d has enter table.\n", friend_etr_lev_order[i][0]);
        flag = -1;   // reset flag.
        int j = 0;
        while (j < total) {
            // check if there is empty chair.
            if (table_queue[j][2] == 0 && flag == -1) {
                table_queue[j][0] = friend_etr_lev_order[i][0];     // who in table.
                table_queue[j][1] = friend_etr_lev_order[i][2];     // leave time.
                table_queue[j][2] = 1;
                printf("chair#%d  has empty. enter.\n", j);
                flag = j;
            }
            if (friend_etr_lev_order[i][1] >= table_queue[j][1]) {
                printf("%d >= [Friend %d] %d (has leaved).\n", friend_etr_lev_order[i][1], table_queue[j][0], table_queue[j][1]);
                if (flag == -1) {
                    printf("Put friend at table: %d.\n",j);
                    table_queue[j][0] = friend_etr_lev_order[i][0];     // who in table.
                    table_queue[j][1] = friend_etr_lev_order[i][2];     // leave time.
                    table_queue[j][2] = 1; // occupied.
                    flag = j;
                } else {
                    table_queue[j][2] = 0; // occupied.
                    printf("Chair #%d is empty.\n", j);
                }
            }
            j++;
        }
        if (flag == -1) {
            printf("All chairs are full.(%d)\n", total);
            table_queue[total][0] = friend_etr_lev_order[i][0];     // who in table.
            table_queue[total][1] = friend_etr_lev_order[i][2];     // leave time.
            table_queue[total][2] = 1; // occupied.
            flag = total;
            total++;
        }
        if (targetFriend == friend_etr_lev_order[i][0]) {
            flag_target_friend_entered = 1;
            printf("Entered............\n");
        }
        i++;
    }
    return flag;
}