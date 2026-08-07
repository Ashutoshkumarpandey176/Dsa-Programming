class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        int n = arr.size();
        int low = 0;

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            if (arr[i] != 0) {
                ans.insert(ans.begin() + low, arr[i]);
                low++;
            }
            else {
                ans.insert(ans.begin() + low, 0);
                low++;

                ans.insert(ans.begin() + low, 0);
                low++;
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i] = ans[i];
        }
    }
};