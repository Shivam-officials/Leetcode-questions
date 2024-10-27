class Solution
{
    public:

        void maxProfitRE(vector<int> &prices, int i, int &minPrice, int &maxProfit)
        {
           	//base case 
            if (i == prices.size()) return;

           	// 1 case 
            if (prices[i] < minPrice) minPrice = prices[i];
            int currentProfit = prices[i] - minPrice;
            if (currentProfit > maxProfit) maxProfit = currentProfit;

            // vaki recrusrion sambhal lega
            return maxProfitRE(prices, i + 1, minPrice, maxProfit);
        }

    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX, maxProfit = INT_MIN;

        maxProfitRE(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};