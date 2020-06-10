class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int DP[5005] ;
        memset(DP, 0 , sizeof(DP));
        DP[0] = 1;
        // for( int i = 0 ; i < coins.size() ; i++) {
        //     DP[coins[i]] = 1; 
        // }
        for(int i = 0 ; i < coins.size() ; i++ ) {
            DP[coins[i]] += 1;
            for(int j = 1 ; j + coins[i] <= amount ; j++) {
                DP[j+coins[i]] += DP[j] ; 
            }
            for (int j = 0 ; j <= 5 ; j++) {
                cout << DP[j] << " " ;
            }
            cout << endl; 
        }
        return DP[amount];
    }
};