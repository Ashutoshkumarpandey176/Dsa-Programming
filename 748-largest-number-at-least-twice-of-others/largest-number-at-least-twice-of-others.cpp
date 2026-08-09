class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=0;
        int maxiidx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                maxiidx=i;
            }
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maxi)
            {
                ans.push_back(nums[i]);
            }
            else
            {
                ans.push_back(2*nums[i]);
            }
        }
        int left=0;
        while(left!=ans.size())
        {
            if(ans[left]>maxi)
            {
                return -1;
            }
            else
            {
                left++;
            }
        }
        return maxiidx;
    }
};