class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int left = 0;
        int right = 0;
        int maxlen = 0;
        int zero = 0;

        while (right < nums.size()) {

            if (nums[right] == 0)
                zero++;

            while (zero > 1) {
                if (nums[left] == 0)
                    zero--;
                left++;
            }

            int len = right - left + 1;
            maxlen = max(maxlen, len);

            right++;
        }

        return maxlen - 1;
    }
};