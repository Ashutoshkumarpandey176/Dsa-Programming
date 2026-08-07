class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int low = 0;  
        int high = 1;  
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                ans[low] = nums[i];
                low += 2;
            } else {
                ans[high] = nums[i];
                high += 2;
            }
        }

        return ans;
    }
};