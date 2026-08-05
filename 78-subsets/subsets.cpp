class Solution {
public:
    void allsubset(vector<int>&arr,vector<int>&ans,vector<vector<int>>&result,int i){
        if(i==arr.size())
        {
            result.push_back(ans);
            return;
        }
        ans.push_back(arr[i]);
        allsubset(arr,ans,result,i+1);
        ans.pop_back();
        allsubset(arr,ans,result,i+1);
     
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int>ans;
        vector<vector<int>>result;
        allsubset(arr,ans,result,0);
          return result;
    }
   
};