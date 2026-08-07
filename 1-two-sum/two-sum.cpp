class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<=nums.size()-1;i++)
        {
            int need=target-nums[i];
            if(mp.find(need)!=mp.end())
            {
                return {mp[need],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};