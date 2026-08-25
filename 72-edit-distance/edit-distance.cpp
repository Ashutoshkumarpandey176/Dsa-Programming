class Solution {
public:
    int dp[1001][1001];
    int solve(string word1, string word2,int m,int n,int i,int j)
    {
        if(j==n)
        {
            return m-i;
        }
        if(i==m)
        {
            return n-j;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(word1[i]==word2[j])
        {
           return dp[i][j]=solve(word1,word2,m,n,i+1,j+1);
        }
        else
        {
        int insert= solve(word1,word2,m,n,i,j+1);
        int Delete= solve(word1,word2,m,n,i+1,j);
        int Replace=solve(word1,word2,m,n,i+1,j+1);
        return dp[i][j] = 1 + min({insert, Delete, Replace});
        }
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,m,n,0,0);
    }
};