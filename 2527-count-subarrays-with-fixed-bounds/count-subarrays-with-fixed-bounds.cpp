class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long ans=0;
        int minkpostion=-1;
        int maxkpostion=-1;
        int culpritidx=-1;

        for(int i=0;i<nums.size();i++)
        {
            //This is the index value that is out of range:
            if(nums[i]<minK || nums[i]>maxK)
                culpritidx=i;
            if(nums[i]==minK)
                minkpostion=i;
            if(nums[i]==maxK)
                maxkpostion=i;
            long long smaller=min(minkpostion,maxkpostion);
            
            long long  temp = smaller-culpritidx;

            if(temp<=0)
            {
                ans+=0;
            }
            else
            {
                ans+=temp;
            }
        }
        return ans;
    }
};