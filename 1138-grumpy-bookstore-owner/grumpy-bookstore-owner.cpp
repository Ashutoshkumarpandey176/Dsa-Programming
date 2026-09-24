class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();

        int maxun_satisfy_coust=0;//in any winow max consticative unsatisfy window min

        //This is the only first window ans;
        int currUnsat=0;
        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i]==1)
            {
                currUnsat+=customers[i];
            }
        }
        
        int j=minutes;
        int i=0;
       maxun_satisfy_coust=currUnsat;
        while(j<n)
        { // Add the new element entering the window
            if (grumpy[j] == 1) {
                currUnsat += customers[j];
            }

            // Remove the old element leaving the window
            if (grumpy[i] == 1) {
                currUnsat -= customers[i];
            }

            maxun_satisfy_coust = max(maxun_satisfy_coust, currUnsat);

            i++;
            j++;
        }
        int sum=0;
        for(int i=0;i<grumpy.size();i++)
        {
            if(grumpy[i]==0)
            {
                sum+=customers[i];
            }
        }
        return maxun_satisfy_coust+sum;
    }
};