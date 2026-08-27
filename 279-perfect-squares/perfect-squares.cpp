class Solution {
public:
  int dp[100001];
   int solve(int n)
   {
      if(n==0)
      {
        return 0;
      }
      if(dp[n]!=-1)
      {
        return dp[n];
      }
      int mincount=INT_MAX;
      for(int i=1;i*i<=n;i++)
      {
         int result=1+solve(n-i*i);
         mincount=min(mincount,result);
      }
      return dp[n]=mincount;
   }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};