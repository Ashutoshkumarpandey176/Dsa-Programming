class Solution {
public:
    int n;
    int dp[1001][1+10001];
    static bool myFunction(string &words1,string &words2)
    {
        return words1.length()<words2.length();
    }
    bool ispredi(string &prev,string &curr)
    {
        int l1=prev.length();
        int l2=curr.length();
        if(l2-l1==1)
        {
            int i=0;
            int j=0;
            while(i<l1 && j<l2)
            {
                if(prev[i]==curr[j])
                    i++;
                j++;
            }
             return i==l1;
        }
        return false;
    }
    int solve(vector<string>&words,int prev,int curridx)
    {
       if(curridx>=n)
       {
          return 0;
       }
       if(dp[prev+1][curridx]!=-1)
       {
          return dp[prev+1][curridx];
       }
        int take=0;
        int nottake = solve(words, prev, curridx + 1);

       if(prev==-1 || ispredi(words[prev],words[curridx]))
       {
          take=1+solve(words,curridx,curridx+1);
       }
       return dp[prev+1][curridx]=max(take,nottake);
    }
    int longestStrChain(vector<string>& words) {
        n=words.size();
        sort(words.begin(), words.end(), myFunction);
        memset(dp,-1,sizeof(dp));
        return solve(words,-1,0);
    }
};