class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size() - 1 ; 
        
        int mid  ;
        
        while (abs(high - low) > 5) {
            mid = (high + low) / 2;
            if(nums[mid] >= target) {
                high = mid;
            } else {
                low = mid;
            }
        }
        int ans = high + 1 ;
        
        for(int i = low ; i <= high ; i++ ) {
            if(nums[i] >= target) {
                ans = i;
                break;
            }
            
        }
        return ans ; 
    }
};