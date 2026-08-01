class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
      int maxsum=0;
      for(auto nums:accounts){
         int sum=0;
         for(int x:nums){
            sum=sum+x;
            maxsum=max(maxsum,sum);
         }
      }
      return maxsum;
    }
};