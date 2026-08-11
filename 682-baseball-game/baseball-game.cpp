class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>ans;
        int low=0;
        int sum=0;

        while(low<operations.size())
        {
            if(operations[low]=="D")
            {
                int newans=2*ans.back();
                ans.push_back(newans);
            }
            else if(operations[low]=="C")
            {
                ans.pop_back();
            }
            else if(operations[low]=="+")
            {
                int newans=ans[ans.size()-1]+ans[ans.size()-2];
                ans.push_back(newans);
            }
            else
            {
                ans.push_back(stoi(operations[low]));
            }

            low++;
        }

        for(int i=0;i<ans.size();i++)
        {
            sum+=ans[i];
        }

        return sum;
    }
};
