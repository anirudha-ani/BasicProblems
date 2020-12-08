class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans ; 
        for(int i = 0 ; i < n ; i++) {
            vector<int> empty(n);
            ans.push_back(empty);
        }
        int column = 0 ;
        int row = 0 ; 
        
        string direction = "right";
        int current = 1 ;
        int square = n * n ;
        while(current != square+1) {
            // for(int i = 0 ; i < n ; i++) {
            //     for(int j = 0 ; j < n ; j++) {
            //         cout << ans[i][j] <<" ";
            //     }
            //     cout << endl <<endl;
            // }
            ans[row][column] = current;
            current++;
            if(direction == "right") {
                if(column + 1 >= n || ans[row][column+1] != 0) {
                    direction = "down";
                    row+=1;
                } else {
                    column++;
                }
            } else if(direction == "down") {
                if(row + 1 >= n || ans[row+1][column] != 0) {
                    direction = "left";
                    column-=1;
                } else {
                    row++;
                }
            } else if(direction == "left") {
                if(column - 1 < 0 || ans[row][column-1] != 0) {
                    direction = "up";
                    row-=1;
                } else {
                    column--;
                }
            } else if(direction == "up") {
                if(row - 1 < 0 || ans[row-1][column] != 0) {
                    direction = "right";
                    column+=1;
                } else {
                    row--;
                }
            }
        }
        return ans;
    }
};