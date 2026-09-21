class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        int n = nums.size();

        long long sum = 0;

        // Total Sum
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        long long LS = 0;
        long long RS = 0;

        int result = INT_MAX;
        int idx = -1;

        for(int i = 0; i < n; i++)
        {
            LS += nums[i];       // Left sum
            RS = sum - LS;       // Right sum

            int n1 = i + 1;      // Left elements
            int n2 = n - n1;     // Right elements

            long long left_avg = LS / n1;

            long long right_avg = 0;

            if(i != n - 1)
                right_avg = RS / n2;

            int diff = abs(left_avg - right_avg);

            if(result > diff)
            {
                result = diff;
                idx = i;
            }
        }

        return idx;
    }
};