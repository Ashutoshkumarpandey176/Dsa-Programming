class Solution {
public:
    long long countSubstrings(string s, char c) {
        int curr_count=0;
        long long ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==c)
            {
                curr_count++;
                ans=ans+curr_count;
            }
        }
        return ans;
    }
};