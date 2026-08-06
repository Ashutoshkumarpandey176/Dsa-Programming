class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low=0;
        int high=1;
        int idx=0;
        while(high!=nums.size())
        {
             if(nums[low]==nums[high])
             {
                 high++;
             }
            else
            {
                nums[idx]=nums[low];
                idx++;
                low=high;
                high++;
            }
        }
        nums[idx]=nums[low];
        idx++;
        return idx;
    }

};