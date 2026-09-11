class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int prevDevicecount=0;
        int result=0;
        for(int i=0;i<n;i++)
        {
            int currDeviceCount=0;

            for(char &ch:bank[i])
            {
                if(ch=='1')
                {
                    currDeviceCount++;
                }
            }

            result+=(currDeviceCount*prevDevicecount);

            if(currDeviceCount!=0)
            {
                prevDevicecount=currDeviceCount;
            }
        }
        return result;
    }
};