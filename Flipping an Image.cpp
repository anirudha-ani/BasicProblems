class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int temp,length ; 
        for(int i = 0 ; i<A.size() ; i++) {
            length = A[i].size(); 
            if(length%2 != 0) {
                
                A[i][(length/2) ] ^= 1;
            }
            for(int j = 0 , k = A[i].size()-1 ; j < k ; j++,k--) {
                temp = A[i][j] ^ 1 ; 
                A[i][j] = A[i][k] ^ 1 ;
                A[i][k] = temp;
            }
        }
        return A;
    }
};