class Solution {
public:
    int dp[2501][2501];
    int solve(vector<int>& nums, int idx, int prev)
    {
        if(idx == nums.size())
        {
            return 0;
        }
        if(dp[idx][prev + 1] != -1)
        {
            return dp[idx][prev + 1];
        }
        // we do intial prev+1 beacuse we intilaze it prev with minus
        int take = 0;
        if(prev == -1 || nums[prev] < nums[idx])
        {
            take = 1 + solve(nums, idx + 1, idx);
        }
        int skip = solve(nums, idx + 1, prev);
        return dp[idx][prev + 1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums)
    {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};