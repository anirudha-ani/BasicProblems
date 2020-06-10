bool sortby (vector<int> a , vector<int> b) {
    if(a[0] == b[0]) {
        return (a[1] < b[1]);
    }
    return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), sortby);
    for(int i =0 ; i < people.size() ; i++)
    {
        printf("%d :: %d\n", people[i][0], people[i][1]);
    }
    vector<vector<int>> ans ;
    vector <int> temp;
    temp.push_back(-1);
    temp.push_back(-1);

    for(int i = 0 ; i < people.size() ; i++)
    {
        ans.push_back(temp);
    }

    int counter, index;

    for(int i =0 ; i < people.size() ; i++)
    {
        counter = people[i][1];
        index = 0;

        while(counter!=0)
        {
            if(ans[index][0] == -1 || ans[index][0] >= people[i][0])
            {
                counter--;
            }
            index++;
        }
        cout <<"HERE"<<endl;
        while(ans[index][0] != -1)
        {
            index++;
            cout << "==" << index << endl;
        }
        ans[index] = people[i];
        cout << ans[index][0] << "::" << ans[index][1] << "::" << index <<endl;
    }
        
        return ans;
    }
    
};