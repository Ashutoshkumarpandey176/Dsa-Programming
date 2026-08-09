class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(n + 1, 0);
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        int duplicate = 0;
        int notfound = 0;

        for (int i = 1; i <= nums.size(); i++) {
            if (freq[i] == 2) {
                duplicate = i;
            }
            else if (freq[i] == 0) {
                notfound = i;
            }
        }

        ans.push_back(duplicate);
        ans.push_back(notfound);

        return ans;
    }
};