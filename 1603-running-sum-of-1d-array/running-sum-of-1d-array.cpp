class Solution {
public:
    vector<int> runningSum(vector<int>& arr) {
      vector<int>ans;
      int prefix=0;
      for(int i=0;i<arr.size();i++){
          prefix=prefix+arr[i];
          ans.push_back(prefix);
      }

        return ans;
    }
};