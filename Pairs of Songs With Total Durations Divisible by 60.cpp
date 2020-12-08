class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> modu(60,0) ; 
        int counter = 0 ; 
        int modV;
        for(int i = 0 ; i < time.size() ; i++) {
            modV = time[i] % 60; 
            if(modV == 0) {
                counter += modu[0];
                modu[0] = modu[0] + 1 ;
            } else {
                counter += modu[60 - modV];
                modu[modV] = modu[modV] + 1;
            }
        }
        return counter ; 
    }
};