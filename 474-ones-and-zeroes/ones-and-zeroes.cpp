class Solution {
public:
    int dp[1000][101][101];
    int solve(vector<pair<int,int>>&count,int m,int n,int idx)
    {
       if(idx >= count.size() || (m == 0 && n == 0))
       {
          return 0;
       }
        //Above is base case
       if(dp[idx][m][n]!=-1)
       {
          return dp[idx][m][n];
       }
        int take=0;
        if(count[idx].first<=m && count[idx].second<=n)
        {
    take=1+solve(count,m-count[idx].first,n-count[idx].second,idx+1);
        }
        int nottake=solve(count,m,n,idx+1);

        return dp[idx][m][n]=max(take,nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N=strs.size();
        vector<pair<int,int>>count(N);
        for(int i=0;i<N;i++)
        {
             int countZero=0;
             int countone=0;
             for(const char&ch:strs[i])
             {
                if(ch=='0')
                    countZero++;
                else
                    countone++;
             }
             count[i]={countZero,countone};
        }
       memset(dp, -1, sizeof(dp));
        //The above is bassicaly we use for make the cout vactor<pair
        return solve(count,m,n,0);
    }
};