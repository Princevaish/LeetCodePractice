class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxPrice=0;
        for(int price: prices)
        {
            if(price<minPrice)
            {
                minPrice=price;
            }
            int ans=price-minPrice;
            if(ans>maxPrice)
            {
                maxPrice=ans;
            }
        }
        return maxPrice;

        
    }
};