//Best Time to Buy and Sell Stock
DP
here we need to keep in min that if a person sells a stock on a particular day then he will but it on minimum of i-1 day

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,mini=prices[0],cost;
        for(int i=0;i<prices.size();i++){
            cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(prices[i],mini);
        }
        return profit;
    }
};