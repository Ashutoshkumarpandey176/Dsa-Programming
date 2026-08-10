class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int low=0;
       int five=0;
       int ten=0;
       while(low!=bills.size())
       {
          if(bills[low]==5)
          {
             five++;
             low++;
          }
          else if(bills[low]==10)
          {
             if(five>=1)
             {
                five--;
                 ten++;
                 low++;
             }
             else
             {
                return false;
             }
          }
          else if(bills[low]==20)
          {
             if(five>=1 && ten>=1)
             {
                 five--;
                 ten--;
                 low++;
             }
             else if(five>=3)
             {
                five=five-3;
                low++;
             }
             else
             {
                return false;
             }
          }
       }
        return true;
    }
};