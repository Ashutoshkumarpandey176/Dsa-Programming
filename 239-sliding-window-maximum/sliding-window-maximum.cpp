class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq;   // stores indices
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            // Step 1: Remove indices outside the current window
            while (!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }

            // Step 2: Remove smaller elements from the back 
            while (!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();//yay chota element  ko instant back sai delete karta hai 
            }

            // Step 3: Add current index
            deq.push_back(i);

            // Step 4: Add maximum of current window
            if (i >= k - 1) {
                ans.push_back(nums[deq.front()]);
            }
        }

        return ans;
    }
};