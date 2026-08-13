class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)
        {
            return nums.size();
        }
        int low=2;
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]!=nums[low-2])
            {
                nums[low]=nums[i];
                low++;
            }
        }
        return low;
    }
};