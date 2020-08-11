//Simple memory efficient but higher time complexity solution
//Counting can give a higher memory but lower complexity solution
class Solution
{
public:
    static bool sortBy(int a, int b)
    {
        return a > b;
    }
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), sortBy);
        int ans = 0;

        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] == i + 1)
            {
                ans = max(ans, citations[i]);
            }
            else if (citations[i] > i + 1)
            {
                ans = max(ans, i + 1);
            }
        }
        return ans;
    }
};