class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum=0;
        for(int x:nums){
            totalsum+=x;
        }
        int leftsum=0;
        int rightsum=0;
        for(int i=0;i<nums.size();i++){
            rightsum=totalsum-leftsum-nums[i];
            if(rightsum==leftsum){
                return i;
            }
            leftsum=leftsum+nums[i];
        }
        return -1;
    }
};