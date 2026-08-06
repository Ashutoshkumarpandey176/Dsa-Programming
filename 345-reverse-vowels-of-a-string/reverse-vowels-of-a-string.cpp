class Solution {
public:
    bool isvowel(char ch) {
        ch = tolower(ch);

        return (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u');
    }

    string reverseVowels(string s) {

        int low = 0;
        int high = s.size() - 1;

        while (low < high) {

            if (isvowel(s[low]) && isvowel(s[high])) {
                swap(s[low], s[high]);
                low++;
                high--;
            }
            else if (!isvowel(s[low])) {
                low++;
            }
            else {
                high--;
            }
        }

        return s;
    }
};