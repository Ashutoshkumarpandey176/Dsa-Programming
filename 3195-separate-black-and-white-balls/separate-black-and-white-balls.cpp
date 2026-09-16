class Solution {
public:
    long long minimumSteps(string s) {
        int low = 0;
        int high = low + 1;
        long long count = 0;

        while (high != s.size()) {
            if (s[low] == '1' && s[high] == '0') {
                int temp = low;

                while (temp >= 0 && s[temp] == '1') {
                    swap(s[temp], s[high]);
                    count += high - temp;
                    high++;
                    temp--;
                }

                low++;
            }
            else if (s[low] == '0') {
                low++;
                high++;
            }
            else if (s[low] == '1' && s[high] == '1') {
                high++;
            }
        }

        return count;
    }
};