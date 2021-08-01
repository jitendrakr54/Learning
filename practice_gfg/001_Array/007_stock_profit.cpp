// Best time to buy and Sell stock

#include <iostream>
#include <vector>

int maxProfit(std::vector<int> price) {
    int maxProfit = 0;
    for(int i=0; i<price.size(); i++) {
        for(int j=i+1; j<price.size(); j++) {
            int profit = price[j] - price[i];
            if(profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }
    return maxProfit;
}

int main() {
    std::vector<int> price1{7, 1, 3, 2, 6, 8, 5};
    std::vector<int> price2{7, 6, 5, 4, 3, 2, 1};
    std::cout<<"MaxProfit: "<<maxProfit(price2)<<"\n";
    return 0;
}