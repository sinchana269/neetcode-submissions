#include <vector>

class Solution {
public:
    /**
     * @brief Calculates the maximum profit achievable with infinite transactions.
     * Evaluated using the Greedy Choice Property: capturing all positive adjacent deltas.
     * 
     * @param prices A vector representing the stock price on each day.
     * @return The maximum total profit as an integer.
     */
    int maxProfit(std::vector<int>& prices) {
        int totalProfit = 0;
        int n = prices.size();
        
        // Edge case: If the array has less than 2 days, no transactions can be made.
        if (n < 2) {
            return 0;
        }

        // Iterate through the time series starting from the second day.
        for (int i = 1; i < n; ++i) {
            
            // If the price increased from yesterday to today, capture the delta.
            // This relies on the mathematical principle that sum of consecutive 
            // positive differences equals the total difference between local minima and maxima.
            if (prices[i] > prices[i - 1]) {
                totalProfit += (prices[i] - prices[i - 1]);
            }
        }

        return totalProfit;
    }
};