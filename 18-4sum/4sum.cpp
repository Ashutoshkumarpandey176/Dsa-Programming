class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     sort(nums.begin(),nums.end());
       set<vector<int>>s;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                 int left=j+1;
                 int right=nums.size()-1;
                 long long sum=0;
                 while(left<right)
                 {
                    sum=(long) (long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target)
                    {
                        s.insert({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                    else if(sum<target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                 }

            }

        }
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};
               