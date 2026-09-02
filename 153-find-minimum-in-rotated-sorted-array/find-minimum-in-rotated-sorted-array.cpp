class Solution {
public:

    int minfind(vector<int>& nums, int n, int low, int high)
    {
        int min = nums[low];

        while (low <= high)
        {
            if (nums[low] < min)
                min = nums[low];

            low++;
        }

        return min;
    }

    int findMin(vector<int>& nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int low = 0;
        int high = n - 1;

        int mid = low + (high - low) / 2;

        int leftmostmid = minfind(nums, n, 0, mid);

        int rightmostmid = minfind(nums, n, mid + 1, high);

        return min(leftmostmid, rightmostmid);
    }
};
