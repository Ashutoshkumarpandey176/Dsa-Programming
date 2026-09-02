class Solution { 
public: 
    int check(vector<int>& nums, int low, int high, int target) 
    { 
        while(low <= high) 
        { 
            int mid = low + (high - low) / 2; 
            
            if(nums[mid] == target) 
            { 
                return mid; 
            } 
            
            // Left part sorted hai
            if(nums[low] <= nums[mid]) 
            { 
                if(nums[low] <= target && target < nums[mid]) 
                { 
                    high = mid - 1; 
                } 
                else 
                { 
                    low = mid + 1; 
                } 
            } 
            
            // Right part sorted hai
            else 
            { 
                if(nums[mid] < target && target <= nums[high]) 
                { 
                    low = mid + 1; 
                } 
                else 
                { 
                    high = mid - 1; 
                } 
            } 
        } 
        
        return -1; 
    } 
    
    int search(vector<int>& nums, int target) 
    { 
        int low = 0; 
        int high = nums.size() - 1; 
        
        return check(nums, low, high, target); 
    } 
};