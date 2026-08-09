class Solution {
public:
    int thirdMax(vector<int>& nums) {

        set<int> st;
        for(int x : nums)
            st.insert(x);

        if(st.size() < 3)
            return *st.rbegin();

        auto it = st.rbegin();
        ++it;                  
        ++it;                  

        return *it;
    }
};