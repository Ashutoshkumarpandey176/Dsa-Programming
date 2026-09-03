class Solution {
public:
    bool check(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;
            //yay hai jab left or right equal hai to left++ and right--
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            //yay hai jab maira left side of the array sorted hai
            else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            //eay hai jab right side of the array jab sorted hoa 
            else {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return false;
    }

    bool search(vector<int>& nums, int target) {
        return check(nums, 0, nums.size() - 1, target);
    }
};
