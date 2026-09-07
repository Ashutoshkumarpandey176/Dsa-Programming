class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>frq1(26,0);
        vector<int>frq2(26,0);

        if(word1.size()!=word2.size())
        {
            return false;
        }

        for(int i=0;i<word1.size();i++)
        {
            frq1[word1[i]-'a']++;
        }

        for(int i=0;i<word2.size();i++)
        {
            frq2[word2[i]-'a']++;
        }

        // Same characters must exist in both strings
        for(int i=0;i<26;i++)
        {
            if((frq1[i]==0 && frq2[i]!=0) || (frq1[i]!=0 && frq2[i]==0))
            {
                return false;
            }
        }

        sort(frq1.begin(),frq1.end());
        sort(frq2.begin(),frq2.end());

        for(int i=0;i<26;i++)
        {
            if(frq1[i]!=frq2[i])
            {
                return false;
            }
        }

        return true;
    }
};