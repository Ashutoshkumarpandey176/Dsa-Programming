class Solution {
public:
    int strStr(string haystack, string needle) {

        int j = 0;

        while (j < haystack.size()) {

            int i = 0;
            int count = 0;
            int start = j;

            while (j < haystack.size() &&i < needle.size() && haystack[j] == needle[i]) {

                i++;
                j++;
                count++;
            }

            if (count == needle.size()) {
                return start;
            }

            j = start + 1;
        }

        return -1;
    }
};