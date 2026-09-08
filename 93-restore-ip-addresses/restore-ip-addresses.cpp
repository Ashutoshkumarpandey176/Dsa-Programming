class Solution {
public:
    int n;
    vector<string>result;
    bool isvalid(string str)
    {
        if(str[0]=='0')
        {
            return false;
        }
        int val=stoi(str);
        if(val>255)
        {
            return false;
        }
        return true;
    }
    void solve(string &s,int idx,int part,string curr)
    {
        if(idx==n && part==4)
        {
            curr.pop_back();//last ka dot remove kar raha hu decimal 
            result.push_back(curr);
            return;
        }
       if(idx+1<=n)
       {
        solve(s,idx+1,part+1,curr+s.substr(idx,1)+".");
        //agar eek length ka id leaya to
       }
       if(idx+2<=n && isvalid(s.substr(idx,2)))
       {
         solve(s,idx+2,part+1,curr+s.substr(idx,2)+".");
       }
        if(idx+3<=n && isvalid(s.substr(idx,3)))
        {
          solve(s,idx+3,part+1,curr+s.substr(idx,3)+".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n=s.length();
        result.clear();
        if(n>12)
        {
            return {};
        }
        int part=0;
        string curr="";
      //function name(string,index,parts,currstring);
        solve(s,0,part,curr);
        return result;
    } 
};