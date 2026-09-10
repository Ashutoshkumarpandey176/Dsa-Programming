class Solution {
public:

    int beautifulSubstrings(string s, int k) {
        int size = s.length();
        int count = 0;

        for(int i = 0; i < size; i++)
        {
            int vowelcount = 0;
            int consonetcount = 0;

            for(int j = i; j < size; j++)
            {
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' ||
                   s[j] == 'o' || s[j] == 'u')
                {
                    vowelcount++;
                }
                else
                {
                    consonetcount++;
                }

                if(vowelcount == consonetcount &&
                   (vowelcount * consonetcount) % k == 0)
                {
                    count++;
                }
            }
        }

        return count;
    }
};