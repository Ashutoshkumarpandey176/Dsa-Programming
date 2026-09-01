class Solution {
public:
    bool isSubsequence(string s, string t) {
        int low=0;
        int high=0;
        int count=0;
        while(high!=t.size())
        {
            if(s[low]==t[high])
            {
                low++;
                high++;
                count++;
            }
            else
            {
                high++;
            }
        }
        return count==s.size();
    }
};