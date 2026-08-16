class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256,0);
        int left=0;
        int maxlen=0;
        int right=0;
         while(right!=s.size()){
             freq[s[right]]++;
             while(freq[s[right]]>1)
             {
                freq[s[left]]--;
                left++;
             }
             maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};