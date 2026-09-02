class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(mid%2==1)  //agar even odd psotion distrud ho gaya  yay check karta agar ha to mid --
            {
                mid--;
            }
            if(nums[mid]==nums[mid+1]) // yay bolta hai agar miara mid==mid+1 matlab do pair sahi hai to answer right mai hoga
            {
                low=mid+2;
            }
            else
            {
               high=mid;//yay bota hai bahi uppar ka nahi chala muhay chala day high mai mid ko dal dai
            }
        }
        return nums[low];
    }
};