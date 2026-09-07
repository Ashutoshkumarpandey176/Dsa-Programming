class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxwater=0;
        while(left<right)
        {
            int currheight=min(height[left],height[right]);
            int width=right-left;
            int water=currheight*width;
            maxwater=max(maxwater,water);
            if(height[left]<height[right])
            {
               left++;
            }
            else
            {
               right--;
            }
        }
        return maxwater;
    }
};
