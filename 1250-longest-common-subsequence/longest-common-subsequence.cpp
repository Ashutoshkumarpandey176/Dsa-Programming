class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int solve(string &text1,string &text2,int idx1,int idx2)
    {
        if(idx1>=n || idx2>=m)
        {
            return 0;
        }
        if(dp[idx1][idx2]!=-1)
        {
            return dp[idx1][idx2];
        }
        if(text1[idx1]==text2[idx2])
        {
            return  dp[idx1][idx2]=1+solve(text1,text2,idx1+1,idx2+1);
        }
        return dp[idx1][idx2]=max(solve(text1,text2,idx1+1,idx2),solve(text1,text2,idx1,idx2+1));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
         n=text1.size();
         m=text2.size();
         memset(dp,-1,sizeof(dp));
       return solve(text1,text2,0,0);
    }
};