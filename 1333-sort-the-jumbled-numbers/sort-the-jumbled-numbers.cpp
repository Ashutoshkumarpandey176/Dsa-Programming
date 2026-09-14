class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        vector<pair<int, int>> v;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int mapped = 0;
            int place = 1;
            
            if (num == 0) {
                mapped = mapping[0];
            }
            else {
                while (num > 0) {
                    int digit = num % 10;
                    mapped += mapping[digit] * place;
                    place *= 10;
                    num /= 10;
                }
            }
            
            // mapped value, original index
            v.push_back({mapped, i});
        }
        
        // Sort by mapped value, then index
        sort(v.begin(), v.end());
        
        vector<int> ans;
        
        for (auto p : v) {
            ans.push_back(nums[p.second]);
        }
        
        return ans;
    }
};