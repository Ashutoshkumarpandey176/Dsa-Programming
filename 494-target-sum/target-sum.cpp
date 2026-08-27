class Solution {
public:
    int n;
    int dp[2001][201];
    int solve(vector<int>&nums,int target,int sum,int idx)
    {
        if(sum==target && idx==n)
        {
            return 1;
        }
        if(idx==n)
        {
            return 0;
        }
         if(dp[sum+1000][idx]!=-1)
        {
            return dp[sum+1000][idx];
        }
        int plus=solve(nums,target,sum+nums[idx],idx+1);
        int minus=solve(nums,target,sum-nums[idx],idx+1);
        return dp[sum+1000][idx]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target)
    {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
       return solve(nums,target,0,0);
    }
};