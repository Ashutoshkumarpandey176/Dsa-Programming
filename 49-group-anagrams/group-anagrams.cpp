class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<string>st=strs;
      for(int i=0;i<strs.size();i++)
      {
         sort(strs[i].begin(),strs[i].end());
      }
      int low=0;
      vector<vector<string>>ans;
      set<string>s;
      while(low!=strs.size())
      {
         if(s.find(strs[low])!=s.end())
         {
            low++;
            continue;
         }
         vector<string>group;
         int high=low;
         while(high!=strs.size())
         {
            if(strs[low]==strs[high])
            {
                group.push_back(st[high]);
            }
            high++;
         }
         ans.push_back(group);
         s.insert(strs[low]);
         low++;
      }
      return ans;
    }
};

