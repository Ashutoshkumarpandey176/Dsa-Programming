class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int low = 0;
        vector<int> ans;
        if (p.size() > s.size()) return ans;

        vector<int> pCount(26, 0), sCount(26, 0);

        for (int i = 0; i < p.size(); i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        while (low + p.size() <= s.size()) {

            if (pCount == sCount) {
                ans.push_back(low);
            }

            if (low + p.size() < s.size()) {
                sCount[s[low] - 'a']--;
                sCount[s[low + p.size()] - 'a']++;
            }

            low++;
        }

        return ans;
    }
};