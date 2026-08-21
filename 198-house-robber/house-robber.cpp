class Solution {
public:
    int maxrob(vector<int>& nums,int idx,vector<int>&dp)
    {
        if(idx>=nums.size())
        {
            return 0;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        return dp[idx]=max(nums[idx]+maxrob(nums,idx+2,dp),maxrob(nums,idx+1,dp));
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return maxrob(nums,0,dp);
    }
};