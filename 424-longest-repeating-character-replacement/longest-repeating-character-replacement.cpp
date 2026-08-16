class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>count;
        int left=0;
        int maxfreq=0;
        int ans=0;
        for(int right=0;right<s.size();right++)
        {
            count[s[right]]++;
            maxfreq=max(maxfreq,count[s[right]]);
            while((right-left+1)-maxfreq>k)
            {
                count[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};