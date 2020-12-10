class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool strictlyIncreasing = false ;
        bool strictlyDecreasing = false ; 
        bool ans = true;
        for(int i = 1 ; i < arr.size() ; i++) {
            if(arr[i] == arr[i-1]) {
                ans = false ;
                break; 
            }
            else if(arr[i] > arr[i-1]) {
                if(!strictlyDecreasing) {
                    strictlyIncreasing = true;
                } else {
                    ans = false ;
                    break;
                }
            } else {
                if(strictlyIncreasing) {
                    strictlyDecreasing = true;
                } else {
                    ans = false ;
                    break;
                }
            }
        }
        if(!strictlyIncreasing || !strictlyDecreasing) {
            ans = false ;
        }
        return ans;
    }
};