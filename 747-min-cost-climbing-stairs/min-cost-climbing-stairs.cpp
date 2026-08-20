class Solution {
public:
    int mincost(vector<int>&cost,int idx,vector<int>&dp)
    {
       if(idx==0)
       {
         return cost[0];
       }
       if(idx==1)
       {
         return cost[1];
       }
       if(dp[idx]!=-1)
       {
         return dp[idx];
       }
       return dp[idx]=cost[idx]+min(mincost(cost,idx-1,dp),mincost(cost,idx-2,dp));

    }
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
       vector<int>dp(n,-1);
       return min(mincost(cost,n-1,dp),mincost(cost,n-2,dp));
    }
};