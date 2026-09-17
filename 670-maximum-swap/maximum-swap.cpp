class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.length();

        vector<int>maxright(n);//store the idx max index of right
        maxright[n-1]=n-1;
        for(int i=n-2;i>=0;i--)
        {
            int rightmaxidx=maxright[i+1];
            int rightmaxelment=s[rightmaxidx];

            maxright[i]=(s[i]>rightmaxelment) ? i : rightmaxidx;
        }
        for(int i=0;i<n;i++)
        {
            int maxrightindex=maxright[i];

            int MaxRightElement=s[maxrightindex];
            if(s[i]<MaxRightElement)
            {
                swap(s[i],s[maxrightindex]);
                return stoi(s);
            }
        }
      return num;
    }
};