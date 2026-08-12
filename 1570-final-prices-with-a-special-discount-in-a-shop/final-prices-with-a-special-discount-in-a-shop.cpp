class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans;
         int low=0;
         while(low!=prices.size())
         {
            int high=low+1;
            while(high!=prices.size())
            {
                if(prices[low]>=prices[high])
                {
                    int newans=prices[low]-prices[high];
                    ans.push_back(newans);
                    break;
                }
                else
                {
                    high++;
                }
            }
            if(high==prices.size())
            {
                ans.push_back(prices[low]);
            }
            low++;
         }
         return ans;
    }
};