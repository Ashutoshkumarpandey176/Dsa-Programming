class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0;
        int high=height.size()-1;
        int width=0;
        int length=0;
        int maxarea=0;
        int area=0;
        while(low<high)
        {
             width=high-low;
             length=min(height[low],height[high]);
             area=length*width;
             maxarea=max(area,maxarea);
             if(height[low]<height[high]){
                low++;
             }
             else
             {
                high--;
             }
        }
        return maxarea;
    }
};