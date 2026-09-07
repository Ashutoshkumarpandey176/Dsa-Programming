class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<string> newstring;
        
        int rows = strs.size();
        int cols = strs[0].size();

        for (int i = 0; i < cols; i++) {
            string column = "";

            for (int j = 0; j < rows; j++) {
                column.push_back(strs[j][i]);
            }

            newstring.push_back(column);
        }

    int count=0;
    int i=0;
    while(i<newstring.size())
    {
        if(is_sorted(newstring[i].begin(),newstring[i].end()))
        {
            i++;
        }
        else
        {
            count++;
            i++;
        }
    }
    return count;
    }
};
