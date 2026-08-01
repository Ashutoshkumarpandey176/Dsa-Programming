class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> freq(nums.size() + 1, 0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int duplicate=0;
        int num=0;
        for(int i=1;i<=nums.size();i++){
            if(freq[i]==2){
                duplicate=i;
            }
            if(freq[i]==0)
            {
                num=i;
            }
        }
        return {duplicate,num};
    }
};
