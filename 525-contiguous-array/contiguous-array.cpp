class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0]=-1;
        int maxlen=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum=sum-1;
            }
            else
            {
                sum=sum+1;
            }
            if(mp.count(sum))
            {
                maxlen=max(maxlen,i-mp[sum]);
            }
            else
            {
                mp[sum]=i;
            }
        }
        return maxlen;

    }
};