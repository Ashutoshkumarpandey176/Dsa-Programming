class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();

        string result;
        vector<bool>taken(26,false);
        vector<int>lastindex(26);
        //last index we store
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            lastindex[ch-'a']=i;
        }

        for(int i=0;i<n;i++)
    {
            char ch = s[i];
            int idx = ch - 'a';

            if(taken[idx]==true)
                continue;
            
            while(!result.empty() && result.back()>ch && lastindex[result.back()-'a']>i)
            {
                taken[result.back()-'a']=false;
                result.pop_back();
            }
            result.push_back(s[i]);
             taken[ch-'a']=true;
         
    }
       return result;

    }
};