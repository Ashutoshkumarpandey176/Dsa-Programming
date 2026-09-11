class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i=0;i<s.size();i++)
        {
            freq1[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            freq2[t[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(freq1[i]!=freq2[i])
            {
                if(freq2[i]<freq1[i])
                {
                    count+=freq1[i]-freq2[i];
                }
            }
        }
        return count;
    }
};