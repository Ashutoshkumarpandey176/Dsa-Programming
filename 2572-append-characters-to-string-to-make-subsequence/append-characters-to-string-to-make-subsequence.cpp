class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        //i for s and j for t
        
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }

        return t.size() - j;
    }
};