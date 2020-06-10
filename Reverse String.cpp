class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        char temp ;
        
        for(int i = 0, j=length -1 ; i < length / 2 ; i ++, j--) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};