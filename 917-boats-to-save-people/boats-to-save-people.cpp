class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
         int boats=0;
         int low=0;
         int j=people.size()-1;
         while(low<=j)
         {
            if(people[low]+people[j]<=limit)
            {
                low++;
            }
            j--;
            boats++;
         }

        return boats;
    }
};