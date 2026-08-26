class Solution {
public:
    int dp[10001];
    int solve(string& s, int i)
    {
        if(i == s.size())
            return 1;

        if(s[i] == '0')
            return 0;

        if(dp[i] != -1)
            return dp[i];

        if(i + 1 < s.size() && stoi(s.substr(i, 2)) <= 26)
        {
            return dp[i] = solve(s, i + 1)+solve(s, i + 2);
        }

        return dp[i] = solve(s, i + 1);
    }

    int numDecodings(string s)
    {
        memset(dp,-1,sizeof(dp));
        return solve(s, 0);
    }
};