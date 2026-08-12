class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int closest=nums[1]+nums[2]+nums[3];
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int low=i+1;
            int high=nums.size()-1;
            while(low<high)
            {
                 sum=nums[i]+nums[low]+nums[high];
                 if(abs(sum - target) < abs(closest - target))
                {
                      closest = sum;
                 }
                if(sum==target)
                {
                    return sum;
                }
                else if(sum<target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        return closest;
    }
};