class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        int low=0;
        int high=0;
        vector<int>ans;
        while(low<nums1.size())
        {
            high=0;

            while(high<nums2.size())
            {
                if(nums1[low]==nums2[high])
                {
                    high++;

                    while(high<nums2.size() && nums2[high]<=nums1[low])
                    {
                        high++;
                    }

                    if(high<nums2.size())
                    {
                        ans.push_back(nums2[high]);
                    }
                    else
                    {
                        ans.push_back(-1);
                    }

                    break;
                }
                else
                {
                    high++;
                }
            }
            low++;
        }

        return ans;
    }
};

