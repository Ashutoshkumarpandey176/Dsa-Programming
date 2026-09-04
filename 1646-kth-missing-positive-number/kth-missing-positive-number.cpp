class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int nums=1;
       int i=0;
       int n=arr.size();
       while(i<n && k>0)
       {
          if(arr[i]==nums)
          {
            i++;
          }
          else
          {
            k--;
          }
          nums++;
       }
       while(k--)
       {
         nums++;
       }
       return nums-1;
    }
};