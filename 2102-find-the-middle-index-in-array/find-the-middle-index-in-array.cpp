class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
             totalsum+=nums[i];
        }
        int leftsum=0;
        int rightsum=0;
        for(int i=0;i<nums.size();i++){
            rightsum=totalsum-leftsum-nums[i];
            if(rightsum==leftsum){
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;
    }
};