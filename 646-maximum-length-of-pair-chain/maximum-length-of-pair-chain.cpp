class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(vector<vector<int>>& pairs, int idx, int prev) {
        if(idx >= n) return 0;
       if(dp[idx][prev+1]!=-1)
       {
          return dp[idx][prev+1];
       }
        int skip = solve(pairs, idx + 1, prev);
        int take = 0;

        if(prev == -1)
            take = 1 + solve(pairs, idx + 1, idx);
        else if(pairs[prev][1] < pairs[idx][0])
            take = 1 + solve(pairs, idx + 1, idx);

        return dp[idx][prev+1]=max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(pairs.begin(), pairs.end());
        memset(dp,-1,sizeof(dp));
        return solve(pairs, 0, -1);
    }
};