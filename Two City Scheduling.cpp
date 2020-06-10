bool mySort (vector<int> a , vector<int> b) {
       // printf("here\n");
        return abs(a[0] - a[1]) > abs(b[0] - b[1]);
    }
    
class Solution {
public:
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int numberOfPeople = costs.size();
        sort(costs.begin(), costs.end(), mySort);
        int totalCostA = 0;
        int numOfPeopleA = 0;
        int totalCostB = 0 ;
        int numOfPeopleB = 0;
        for(int index = 0 ; index < numberOfPeople ; index++) {
            printf("%d %d %d\n", costs[index][0], costs[index][1], abs(costs[index][0] - costs[index][1]));
            if(costs[index][0] < costs[index][1]) {
                 if(numOfPeopleA < numberOfPeople / 2) {
                     numOfPeopleA++;
                     totalCostA += costs[index][0];
                 }
                else {
                    numOfPeopleB++;
                    totalCostB += costs[index][1];
                }
            }
            else {
                if(numOfPeopleB < numberOfPeople / 2) {
                     numOfPeopleB++;
                     totalCostB += costs[index][1];
                 }
                else {
                    numOfPeopleA++;
                    totalCostA += costs[index][0];
                }
            }
        }
        return totalCostA + totalCostB;
    }
};