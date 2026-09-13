class Solution {
public:
    string customSortString(string order, string s) {
        
        unordered_map<char,int>mp;
        
        for(char ch:s)
        {
            mp[ch]++;
        }
        
        string ans="";
        
        for(int i=0;i<order.size();i++)
        {
            if(mp.find(order[i])!=mp.end())
            {
                while(mp[order[i]]>0)
                {
                    ans.push_back(order[i]);
                    mp[order[i]]--;
                }
            }
        }
       
        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]]!=0)
            {
                while(mp[s[i]]!=0)
                {
                    ans.push_back(s[i]);
                    mp[s[i]]--;
                }
            }
        }
       
        return ans;
    }
};