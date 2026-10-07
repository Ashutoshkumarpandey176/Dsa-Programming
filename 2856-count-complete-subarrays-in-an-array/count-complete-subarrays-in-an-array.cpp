class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        int totalDistinct=st.size();

        unordered_map<int,int>freq;
        int i=0;
        int ans=0;

        for(int j=0;j<n;j++)
        {
            freq[nums[j]]++;
            while(freq.size()==totalDistinct)
            {
                ans+=n-j;
                freq[nums[i]]--;
                if(freq[nums[i]]==0)
                {
                    freq.erase(nums[i]);
                }
                i++;
            }
        }
        return ans;
    }
};






