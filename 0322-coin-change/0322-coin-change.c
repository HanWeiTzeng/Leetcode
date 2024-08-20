
int coinChange(int* coins, int coinsSize, int amount) {
    if (amount < 1) return 0;

    // amount needs to be devided by x*coins[0] + y*coin[1] + z*coins[2] + ...
    int *count = malloc(sizeof(int) * (amount+1));
    count[0] = 0;
    for (int i = 0; i < amount; i++) {
        count[i+1] = INT_MAX-1;
    }
    for (int i = 0; i < coinsSize; i++) { // i = 1
        for (int j = coins[i]; j <= amount; j++) { // 1
            //printf("count[%d] = %d.\n", j, count[j]);
            count[j] = fmin(count[j], count[j-coins[i]]+1);
            //printf("count[j-coins[i]]+1 = %d.\n", count[j-coins[i]]+1);
        }
    }
    if (count[amount] == INT_MAX-1) return -1;

    return count[amount];
}