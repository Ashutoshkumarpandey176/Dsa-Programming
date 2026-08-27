class Solution {
public:
    int n;
    int m;
    int dp[201][201];
    int solve(vector<vector<int>>&grid,int i,int j)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i==n-1 && j==m-1)
        {
            return grid[i][j];
        }
        if(i==n-1)
        {
            return dp[i][j]=grid[i][j]+solve(grid,i,j+1);
        }
        else if(j==m-1)
        {
            return dp[i][j]= grid[i][j]+solve(grid,i+1,j);
        }
        else
        {
          return dp[i][j]=grid[i][j] + min(
                solve(grid, i, j+1),
                solve(grid, i+1, j)
            );
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();//no of row;  i
        m=grid[0].size();//no of col j
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0);

    }
};