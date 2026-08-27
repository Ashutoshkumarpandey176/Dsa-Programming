class Solution {
public:
    int n;
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
        int plus=solve(nums,target,sum+nums[idx],idx+1);
        int minus=solve(nums,target,sum-nums[idx],idx+1);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target)
    {
        n=nums.size();
       return solve(nums,target,0,0);
    }
};