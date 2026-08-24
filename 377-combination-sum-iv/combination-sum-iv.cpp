class Solution {
public:
    int solve(vector<int>& nums, int idx, int target, vector<int>& dp)
    {
        int n = nums.size();

       if(target == 0)
        {
            return 1;
        }

        if(idx >= n)
        {
            return 0;
        }

        if(dp[target] != -1)
        {
            return dp[target];
        }

        int take = 0;

        if(nums[idx] <= target)
        {
            take = solve(nums, 0, target - nums[idx], dp);
        }

        int nottake = solve(nums, idx + 1, target, dp);

        return dp[target] = take + nottake;
    }

    int combinationSum4(vector<int>& nums, int target)
    {
        vector<int> dp(target + 1, -1);

        return solve(nums, 0, target, dp);
    }
};