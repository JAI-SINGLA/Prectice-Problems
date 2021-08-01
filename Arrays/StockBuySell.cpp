class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxDifference=0;
        int buyPrice=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buyPrice){
                buyPrice=prices[i];
            }
            else{
                int difference=prices[i]-buyPrice;
                maxDifference= max(difference,maxDifference);
            }
        }
        return maxDifference;
        
    }
};
