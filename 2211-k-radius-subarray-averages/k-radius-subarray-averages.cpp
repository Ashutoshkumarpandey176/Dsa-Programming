class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> ans(n, -1);

        if (2 * k + 1 > n)
            return ans;

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int j = k;
        int rem = 2 * k + 1;
        int l = 0;

        while (j <= n - k - 1) {

            long long sum = prefix[l + rem] - prefix[l];

            int avg = sum / rem;
            ans[j] = avg;

            j++;
            l++;
        }

        return ans;
    }
};