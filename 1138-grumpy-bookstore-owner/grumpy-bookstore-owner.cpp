class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int low = 0;
        int high = 0;
        vector<int> ans;

        while (low != grumpy.size() && high != customers.size())
        {
            if (grumpy[low] == 0)
            {
                ans.push_back(customers[low]);
            }

            low++;
            high++;
        }

        int sum = accumulate(ans.begin(), ans.end(), 0);

        vector<int> newans;
        int left = 0;
        int right = 0;

        while (left != grumpy.size() && right != customers.size())
        {
            if (grumpy[left] == 0)
            {
                newans.push_back(0);
            }
            else
            {
                newans.push_back(customers[left]);
            }

            left++;
            right++;
        }

        int sum1 = 0;
        int i = 0;
        int j = minutes - 1;
        int k = 0;

        while (k <= j)
        {
            sum1 += newans[k];
            k++;
        }

        high = sum1;

        while (j + 1 < newans.size())
        {
            j++;

            sum1 += newans[j];
            sum1 -= newans[i];

            i++;

            high = max(high, sum1);
        }

        return sum + high;
    }
};