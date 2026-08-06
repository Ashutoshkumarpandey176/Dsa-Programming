class Solution {
public:
    bool isPalindrome(string s) {
        string st;
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                st.push_back(tolower(s[i]));
            }
        }

        int low = 0;
        int high = st.size() - 1;

        while (low < high) {
            if (st[low] == st[high]) {
                low++;
                high--;
            } else {
                return false;
            }
        }

        return true;
    }
};