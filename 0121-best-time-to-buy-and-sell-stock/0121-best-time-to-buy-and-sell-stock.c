//pseudo code
//把  目前最大價差(initialize to 0) &目前最小值((initialize  to price[0])  記住
//跟 目前最大價差 v.s. 當下的價差
//注意Code flow順序


int maxProfit(int* prices, int pricesSize) {
    int current_max_profit = 0;
    int current_cheapest_price = prices[0];
    int tmp_profit = -1;

    for (int i = 1; i < pricesSize; i++) {
        tmp_profit = prices[i] - current_cheapest_price;
        if (tmp_profit > current_max_profit) current_max_profit = tmp_profit;
        if (prices[i] < current_cheapest_price) current_cheapest_price = prices[i];
    }
    return current_max_profit;
}

/*

int maxProfit(int* prices, int pricesSize) {
    int min_price = prices[0];
    int best_price_gap = 0;
    int bgt_price = prices[0];
    int bgt_price_index = 0;

    if (pricesSize <= 1) return 0;
    // store the minimum value
    // store the biggest value gap
    // read to the last one.
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
            bgt_price = prices[i];
            bgt_price_index = i;
        }
        if (prices[i] > bgt_price) {
            bgt_price = prices[i];
            bgt_price_index = i;
        }
        if (best_price_gap < bgt_price - min_price) {
            best_price_gap = bgt_price - min_price;
        }
    }
    return best_price_gap;
}
*/