class Solution {
public:
    bool checkfreq(string &s) {
        int arr[26] = {0};

        for (char &ch : s) {
            arr[ch - 'a']++;

            if (arr[ch - 'a'] > 1)
                return true;
        }

        return false;
    }
    bool buddyStrings(string s, string goal) {
        // Lengths must be equal
        if (s.length() != goal.length())
            return false;

        // If strings are already equal,
        // we need at least one duplicate character
        if (s == goal)
            return checkfreq(s);

        vector<int> index;

        for (int i = 0; i < s.length(); i++) {   // Find positions where strings differ
            if (s[i] != goal[i])
                index.push_back(i);
        }

        if (index.size() != 2) // Exactly two positions must differ
            return false;

        swap(s[index[0]], s[index[1]]);   // Swap the two mismatched characters

        return s == goal;
    }
};