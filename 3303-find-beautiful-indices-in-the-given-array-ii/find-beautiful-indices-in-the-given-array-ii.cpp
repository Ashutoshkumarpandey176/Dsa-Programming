class Solution {
public:

    void computeLps(string pattern, vector<int>& lps)
    {
        int M = pattern.size();
        int len = 0;

        lps[0] = 0;
        int i = 1;

        while(i < M)
        {
            if(pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> KMP(string pat, string txt)
    {
        int N = pat.length();
        int M = txt.length();

        vector<int> lps(N, 0);
        computeLps(pat, lps);

        vector<int> ans;

        int i = 0;
        int j = 0;

        while(i < M)
        {
            if(pat[j] == txt[i])
            {
                i++;
                j++;
            }

            if(j == N)
            {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
            else if(i < M && pat[j] != txt[i])
            {
                if(j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }

        return ans;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> i_indices = KMP(a, s);
        vector<int> j_indices = KMP(b, s);

        vector<int> ans;

        int j = 0;

        for(int i : i_indices)
        {
            while(j < j_indices.size() && j_indices[j] < i - k)
            {
                j++;
            }

            if(j < j_indices.size() && j_indices[j] <= i + k)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};