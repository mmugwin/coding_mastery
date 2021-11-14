#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

int maxProfit(vector<int>& price){
    int p = 0;
    int minP = price[0];
    int currP = 0;

    for(int i = 1; i<price.size(); ++i){
        if(price[i]<minP){
            minP = price[i];
        } else {
            currP = price[i] - minP;
        }
        if(currP > p)  p = currP;
    }
    return p;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // vector<int> prices2 = {7, 6, 4, 3, 1};
    std::cout<< "Max profit: " << maxProfit(prices) << "\n";
    return 0;
}