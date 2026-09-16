class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> v1;
        int curr_idx = 0;
        //This will create for the setence1 word vector
        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == ' ') {
                v1.push_back(sentence1.substr(curr_idx, i - curr_idx));
                curr_idx = i + 1;
            }
        }
        v1.push_back(sentence1.substr(curr_idx));
       //This will create for the sentence2 word character
        vector<string> v2;
        int curr_idx2 = 0;

        for (int i = 0; i < sentence2.size(); i++) {
            if (sentence2[i] == ' ') {
                v2.push_back(sentence2.substr(curr_idx2, i - curr_idx2));
                curr_idx2 = i + 1;
            }
        }
        v2.push_back(sentence2.substr(curr_idx2));
        
        //This will point the itrator of the i  j  k  l for the moveing 
        int i = 0;
        int j = v1.size() - 1;
        int k = 0;
        int l = v2.size() - 1;

        while (i <= j && k <= l && v1[i] == v2[k]) {
            i++;
            k++;
        }

        while (j >= i && l >= k && v1[j] == v2[l]) {
            j--;
            l--;
        }

        return i > j || k > l;
    }
};