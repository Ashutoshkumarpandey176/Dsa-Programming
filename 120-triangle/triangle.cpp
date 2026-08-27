// class Solution {
// public:
//     int n;
//     int dp[201][201];
//     int solve(vector<vector<int>>& triangle,int i,int j)
//     {
//         if(i==n-1)
//         {
//             return triangle[i][j];
//         }
//         if(dp[i][j]!=-1)
//         {
//             return dp[i][j];
//         }
//         int minpath=triangle[i][j]+min(solve(triangle,i+1,j),solve(triangle,i+1,j+1));
//         return dp[i][j]=minpath;
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         n=triangle.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(triangle,0,0);
//     }
// };



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                triangle[i][j] += min(
                    triangle[i + 1][j],
                    triangle[i + 1][j + 1]
                );
            }
        }

        return triangle[0][0];
    }
};