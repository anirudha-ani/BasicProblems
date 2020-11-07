class Solution {
public:
    int calculateSum(vector <int> &nums, int divisor) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            sum += (nums[i] / divisor);
            
            if(nums[i] % divisor != 0) {
                sum++;
            }
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 ; 
        int high = 1000001;
        int mid, sum;
        while(low < high) {
            mid = low + (high - low) / 2;
          sum  = calculateSum(nums, mid);
            //cout << "Mid = " << mid << " sum = " << sum << endl;
        if(threshold < sum ) {
            low = mid +1;
        } else {
            high = mid ;
        }
        }
         return low ; 
    }
   
};