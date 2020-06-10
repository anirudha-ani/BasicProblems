class Solution {

public:
    int totalSum = 0 ;
    vector <int> prefixSum; 
    
    Solution(vector<int>& w) {
        int length = w.size(); 
        prefixSum.clear(); 
        totalSum = 0 ;
        
        for(int i = 0 ; i < length; i++) {
            if(i == 0) {
                prefixSum.push_back(w[i]);
            }
            else {
                prefixSum.push_back(prefixSum[i-1] + w[i]);
                totalSum = prefixSum[i];
            }
        }
        srand ( w.size() );
    }
    
    int pickIndex() {
        
        float random = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * totalSum ;
       
        
        int minIndex = 0 ; 
        int maxIndex = prefixSum.size() - 1;
        int mid ; 
        
        while (maxIndex - minIndex > 5) {
            mid = (maxIndex + minIndex) / 2 ; 
            
            if(prefixSum[mid] < random) {
                minIndex = mid;
            }
            else {
                maxIndex = mid;
            }
        }
        int ans = 0 ; 
        for (int i = minIndex ; i<= maxIndex ;i++) {
            if(prefixSum[i] > random) {
                
                ans = i  ;
                break;
            }
        }
        return ans ; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */