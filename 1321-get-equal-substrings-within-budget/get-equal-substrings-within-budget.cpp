class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0;
        int cost = 0;
        int maxsize = 0;
        int j=0;
        while(j<s.size()) {
            cost += abs(s[j] - t[j]);

            while (cost > maxCost) {
                cost -= abs(s[i] - t[i]);
                i++;
            }
            maxsize = max(maxsize, j - i + 1);
             j++;
        }

        return maxsize;
    }
};