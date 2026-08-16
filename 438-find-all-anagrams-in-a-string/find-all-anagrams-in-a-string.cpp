class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>count1(26,0);
        vector<int>count2(26,0);
        vector<int>ans;
        int left=0;
        if(p.size() >s.size())
        {
            return ans;
        }
        for(int i=0;i<p.size();i++)
        {
             count1[s[i]-'a']++;
             count2[p[i]-'a']++;
        }
        while (left <= s.size() - p.size())
        {
            if(count1==count2)
            {
                ans.push_back(left);
            }
            if(left+p.size()< s.size())
            {
                count1[s[left]-'a']--;
                count1[s[p.size()+left]-'a']++;
            }
            left++;
        }
        return ans;
    }
};