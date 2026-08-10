class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0;
        int right = 0;
        int count = 0;

        while (left < g.size() && right < s.size())
        {
            if (s[right] >= g[left])
            {
                left++;
                right++;
                count++;
            }
            else
            {
                right++;
            }
        }

        return count;
    }
};