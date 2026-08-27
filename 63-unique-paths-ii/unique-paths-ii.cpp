class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int solve(vector<vector<int>>& obstacleGrid,int i,int j)
    {
        if(i >= n || j >= m || obstacleGrid[i][j] == 1)
        {
            return 0;
        }
         if(i == n-1 && j == m-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right=solve(obstacleGrid,i,j+1);
        int down=solve(obstacleGrid,i+1,j);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         n=obstacleGrid.size(); // no of col
         m=obstacleGrid[0].size(); // no of row
         memset(dp,-1,sizeof(dp));
       return solve(obstacleGrid,0,0);
    }
};