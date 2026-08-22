class Solution {
public:
    bool solve(string s, unordered_set<string>& wordDict, int idx, vector<int>& dp)
    {
        if(idx == s.size())
        {
            return true;
        }

        if(dp[idx] != -1)
        {
            return dp[idx];
        }

        for(int i = idx; i < s.size(); i++)
        {
            string temp = s.substr(idx, i - idx + 1);

            if(wordDict.find(temp) != wordDict.end())
            {
                if(solve(s, wordDict, i + 1, dp))
                {
                    return dp[idx] = true;
                }
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size(), -1);

        return solve(s, words, 0, dp);
    }
};