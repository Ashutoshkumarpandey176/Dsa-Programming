class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1)
        {
            return true;
        }
        int num1=nums[0];
        int num2=nums[1];
        int left=0;
        int right=1;

        while(num1==num2 && right<nums.size()-1)
        {
            left++;
            right++;
            num1=nums[left];
            num2=nums[right];
        }

        if(num1<num2)
        {
            while(right!=nums.size())
            {
                if(nums[left]<=nums[right])
                {
                    left++;
                    right++;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            while(right!=nums.size())
            {
                if(nums[left]>=nums[right])
                {
                    left++;
                    right++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};