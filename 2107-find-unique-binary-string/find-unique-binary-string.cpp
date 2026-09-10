class Solution {
public:
    int binaryToDecimal(string binary)
    {
        int decimal = 0;
        int power = 0;

        for(int i = binary.size() - 1; i >= 0; i--)
        {
            decimal += (binary[i] - '0') * pow(2, power);
            power++;
        }

        return decimal;
    }

    string decimalToBinary(int num)
    {
        string binary = "";

        while(num > 0)
        {
            int remainder = num % 2;
            binary += remainder + '0'; //every time we add the render
            num = num / 2;// we devide the no /2
        }

        reverse(binary.begin(), binary.end());

        return binary;
    }

    string findDifferentBinaryString(vector<string>& nums)
    {
        int size = nums[0].size();

        set<int> st;

        for(int i = 0; i < nums.size(); i++)
        {
            int x = binaryToDecimal(nums[i]);
            st.insert(x);
        }

        string ans;

        for(int i = 0; i <= nums.size(); i++)
        {
            if(st.find(i) == st.end())
            {
                ans = decimalToBinary(i);

                while(ans.size() < size)
                {
                    ans = "0" + ans;
                }

                break;
            }
        }

        return ans;
    }
};