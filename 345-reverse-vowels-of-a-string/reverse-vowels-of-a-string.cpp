class Solution {
public:
    bool check(char s)
    {
        if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u'||s=='A'||s=='E'||s=='I'||s=='O'||s=='U')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string reverseVowels(string s) {
        int low=0;
        int high=s.size()-1;
        while(low<=high)
        {
            if(check(s[low])==true && check(s[high])==true)
            {
                swap(s[low],s[high]);
                low++;
                high--;
            }
            else if(check(s[high])==false)
            {
                high--;
            }
            else if(check(s[low])==false)
            {
                low++;
            }
        }
        return s;
    }
};