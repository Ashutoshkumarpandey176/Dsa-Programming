class Solution {
public:
    int n;
    long long dp[100001][2];
    long long solve(vector<int>& nums, int idx, int sign)
    {
        if(idx == n)
            return 0;
        
        if(dp[idx][sign] != LLONG_MIN)
            return dp[idx][sign];

        long long take;

        if(sign == 1)
            take = nums[idx] + solve(nums, idx + 1, 0);
        else
            take = -nums[idx] + solve(nums, idx + 1, 1);

        long long nottake = solve(nums, idx + 1, sign);

        return dp[idx][sign] = max(take, nottake);
    }

    long long maxAlternatingSum(vector<int>& nums)
    {
        n = nums.size();

        for(int i = 0; i < n; i++)
        {
            dp[i][0] = LLONG_MIN;
            dp[i][1] = LLONG_MIN;
        }

        return solve(nums, 0, 1);
    }
};