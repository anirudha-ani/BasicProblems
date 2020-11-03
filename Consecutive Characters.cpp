class Solution {
public:
    int maxPower(string s) {
        int maxi = 1 ;
        int cur = 1 ;
        char curChar = s[0];
        
        for (int i = 1 ; i < s.size() ; i++) {
            if(s[i] == curChar) {
                cur++;
                maxi = max(maxi , cur);
            }
            else {
                curChar = s[i];
                cur = 1 ;
            }
        }
        return maxi;
        
    }
};