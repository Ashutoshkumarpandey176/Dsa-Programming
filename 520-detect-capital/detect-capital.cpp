class Solution {
public:
    bool allcapital(string word)
    {
        for(int i=0;i<word.size();i++)
        {
            if(!isupper(word[i]))
            {
                return  false;
            }
        }
        return true;
    }
     bool allsmall(string word)
    {
        for(int i=0;i<word.size();i++)
        {
            if(!islower(word[i]))
            {
                return  false;
            }
        }
        return true;
    }
     bool firstcapital(string word)
    {
        if(!isupper(word[0]))
        {
            return false;
        }
        for(int i=1;i<word.size();i++)
        {
            if(!islower(word[i]))
            {
                return  false;
            }
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if(allcapital(word)||allsmall(word)||firstcapital(word))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};