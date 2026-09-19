class Solution {
public:

    int sum(int num, vector<int>& nums, int idx)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == idx)
            {
                nums[i] = nums[i] + num;
            }
        }

        return nums[idx];
    }

    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        vector<int> ans;

        for(int k = 0; k < queries.size(); k++)
        {
            int num = queries[k][0];
            int idx = queries[k][1];

            int x = sum(num, nums, idx);

            int evenSum = 0;

            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] % 2 == 0)
                {
                    evenSum = evenSum + nums[i];
                }
            }

            ans.push_back(evenSum);
        }

        return ans;
    }
};