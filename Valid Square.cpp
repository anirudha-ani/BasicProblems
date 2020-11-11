class Solution {
public:
    long long int lengthSquare(vector <int> &p1, vector<int> &p2) {
        long long int ans = (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1]) * (p1[1]-p2[1]);
        return ans;
    }
    
    bool serialEqual (vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        long long int a = lengthSquare(p1,p2) ;
        long long int b = lengthSquare(p2,p3) ;
        long long int c = lengthSquare(p3,p4) ;
        long long int d = lengthSquare(p4,p1) ;
        return a == b
            && b == c
            && c == d
            && a != 0;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
       if(lengthSquare(p1,p2) + lengthSquare(p1,p3) == lengthSquare(p2,p3) 
          &&  lengthSquare(p4,p2) + lengthSquare(p4,p3) == lengthSquare(p2,p3)
         && serialEqual(p1,p2,p4,p3)) {
           return true;
       } else if(lengthSquare(p1,p4) + lengthSquare(p1,p3) == lengthSquare(p4,p3) 
          &&  lengthSquare(p4,p2) + lengthSquare(p2,p3) == lengthSquare(p4,p3)
                 && serialEqual(p1,p4,p2,p3)) {
           return true;
       } else if(lengthSquare(p1,p4) + lengthSquare(p1,p2) == lengthSquare(p4,p2) 
          &&  lengthSquare(p4,p3) + lengthSquare(p2,p3) == lengthSquare(p4,p2)
                 && serialEqual(p1,p4,p3,p2)) {
           return true;
       } else return false;
    }
};