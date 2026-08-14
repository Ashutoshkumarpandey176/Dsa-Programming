class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int count = 0;
        int start = 0;
        int end = 0;
        int low = 0;
        int high = arr.size() - 1;
        int n = arr.size();

        while (low + 1 < n && arr[low] <= arr[low + 1]) {
            low++;
        }

        if (low == n - 1) return 0;

        while (high > 0 && arr[high - 1] <= arr[high]) {
            high--;
        }

        count = min(n - low - 1, high);

        start = 0;
        end = high;

        while (start <= low && end < n) {
            if (arr[start] <= arr[end]) {
                count = min(count, end - start - 1);
                start++;
            } else {
                end++;
            }
        }

        return count;
    }
};