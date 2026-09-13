class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> result;
        unordered_map<string, int> unique_substr;

        // Precompute frequency of every distinct substring
        for (string &str : arr) {
            unordered_set<string> seen;

            for (int i = 0; i < str.length(); i++) {
                for (int j = i + 1; j <= str.length(); j++) {
                    string substr = str.substr(i, j - i);

                    // Count each substring only once per string
                    if (seen.find(substr) == seen.end()) {
                        unique_substr[substr]++;
                        seen.insert(substr);
                    }
                }
            }
        }

        // Find answer for each string
        for (string &str : arr) {
            string shortest = "";

            for (int i = 0; i < str.length(); i++) {
                for (int j = i + 1; j <= str.length(); j++) {
                    string substr = str.substr(i, j - i);

                    if (unique_substr[substr] == 1 &&
                        (shortest == "" ||
                         substr.length() < shortest.length() ||
                         (substr.length() == shortest.length() &&
                          substr < shortest)))
                    {
                        shortest = substr;
                    }
                }
            }

            result.push_back(shortest);
        }

        return result;
    }
};