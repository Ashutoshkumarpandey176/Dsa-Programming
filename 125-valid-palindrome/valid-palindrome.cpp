class Solution {
public:
    bool isPalindrome(string s) {
        string palindrome;
        for(int i=0;i<s.size();i++)
        {
            if(isalnum(s[i]))
            {
                palindrome+=tolower(s[i]);
            }
        }
        string x=palindrome;
        reverse(palindrome.begin(),palindrome.end());
        return x==palindrome;
    }
};