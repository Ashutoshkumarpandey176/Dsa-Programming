class Solution {
public:
    string makeGood(string s) {
        string result="";
        for(char &ch:s)
        {
            if(!result.empty()&&(result.back()+32==ch || result.back()-32==ch))
                result.pop_back();   // agar ekk capital and ell small equal hai  to pop karo last sai
            else
                result.push_back(ch); // agar ekk captial or ekk small na ho to puch karo
        }
        return result;
    }
};