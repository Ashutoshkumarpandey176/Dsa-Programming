class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       if(nums.size()==1)
       {
          return nums[0];
       }
       int sum=0;
       for(int i=0;i<k;i++){
          sum+=nums[i];
       }
       int maxsum=sum;
       int i=0;
       int j=k;
       while(j<nums.size())
       {
          sum=sum-nums[i]+nums[j];
          maxsum=max(maxsum,sum);
          i++;
          j++;
       }
        return (double)maxsum / k;;

    }
};