class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        int maxfreq = 0;

        for (auto x : freq) {
            if (x.second > maxfreq) {
                maxfreq = x.second;
            }
        }

        int left = 0;
        int right = 0;
        int minsubarray = n;

        for (auto x : freq) {
            int i = x.first;

            if (freq[i] == maxfreq) {

                left = 0;
                right = n - 1;

                while (nums[left] != i) {
                    left++;
                }

                while (nums[right] != i) {
                    right--;
                }

                minsubarray = min(minsubarray, right - left + 1);
            }
        }

        return minsubarray;
    }
};