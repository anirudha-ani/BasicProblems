class Solution {
public:
    bool isSubsequence(string s, string t) {
        int length1 = s.length();
        int length2 = t.length();
        
        int index = 0 ; 
        for(int i = 0 ; i < length2 ; i++) {
            if(s[index] == t[i]) {
                index++;
            }
        }
        return index == length1;
    }
};