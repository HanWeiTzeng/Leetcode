int maxProfit(int* prices, int pricesSize) {
    // init max's index = 0;
    int index_best_sell_day = 0;
    int max = 0;
    int minimum_value = prices[0];
    // record the so far minimum value
    for (int i = 1; i < pricesSize; i++) {
        if (max < prices[i] - minimum_value) {
            max = prices[i] - minimum_value;
            index_best_sell_day = i+1;
        }
        if (prices[i] < minimum_value) {
            minimum_value = prices[i];
        }
    }
    // record the max by checking current - minimum value and max's index+1.
    // return max's index.
    return max;
}