class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int maxcount=0;
      map<int,int>mp;
      mp[0]=-1;
      int count=0;
     for(int i=0;i<nums.size();i++)
     {
            if(nums[i]==0)
            {
                count--;
            }
            else
            {
                count++;
            }
            if(mp.count(count))
            {
                maxcount=max(maxcount,i-mp[count]);
            }
            else
            {
                mp[count]=i;
            }
     }
     return maxcount;
    }
};    