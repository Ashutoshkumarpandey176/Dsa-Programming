class Solution {
public:
    int dp[201][10001];
    bool solve(vector<int>&nums,int i,int x)
    {
        if(x==0)
        {
            return true;
        }
        if(i==nums.size())
        {
            return false;
        }
        if(dp[i][x]!=-1)
        {
            return dp[i][x];
        }
        bool take=false;
        if(nums[i]<=x)
        {
            take=solve(nums,i+1,x-nums[i]);
        }
        bool nottake=solve(nums,i+1,x);
       return dp[i][x]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
       int s=accumulate(nums.begin(),nums.end(),0);
       if(s%2!=0)
       {
          return false;
       }
       int x=s/2;
       memset(dp,-1,sizeof(dp));
       return solve(nums,0,x);
    }
};