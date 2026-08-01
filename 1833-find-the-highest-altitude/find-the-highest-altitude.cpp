class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>ans(n+1);
        ans[0]=0;
        int prefix=0;
        for(int i=0;i<gain.size();i++){
            prefix=prefix+gain[i];
            ans.push_back(prefix);
        }
        int maxi=0;
        for(int i=0;i<ans.size();i++)
        {
             maxi=max(maxi,ans[i]);
        }
        return maxi;
    }
};