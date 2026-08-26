class Solution {
public:
    int n;
    int dp[300][5001];
    int solve(vector<int>& coins, int amount, int idx)
    {
        if(amount == 0)
        {
            return 1;
        }
        if(idx >= n)
        {
            return 0;
        }
        if(dp[idx][amount]!=-1)
        {
            return dp[idx][amount];
        }
        if(coins[idx] > amount)
        {
            return solve(coins, amount, idx + 1);
        }
        int take = solve(coins, amount - coins[idx], idx);
        int nottake = solve(coins, amount, idx + 1);
       return dp[idx][amount]=take + nottake;
    }

    int change(int amount, vector<int>& coins)
    {
        n = coins.size();
        memset(dp,-1,sizeof(dp));
        return solve(coins, amount, 0);
    }
};