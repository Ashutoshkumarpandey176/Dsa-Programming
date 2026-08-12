class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int low=j+1;
                int high=nums.size()-1;
                while(low<high)
                {
                long long sum=(long long)nums[i]+nums[j]+nums[low]+nums[high];
                if(sum==target)
                {
                    st.insert({nums[i], nums[j], nums[low], nums[high]});
                    low++;
                    high--;
                }
              else  if(sum<target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
                }
            }
        }
        for(auto x:st)
        {
            ans.push_back(x);
        }
        return ans;

    }
};