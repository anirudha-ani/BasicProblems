class Solution
{
public:
    int titleToNumber(string s)
    {
        long long int power26[8];
        power26[0] = 1;
        for (int i = 1; i < 8; i++)
        {
            power26[i] = power26[i - 1] * 26;
        }
        long long int ans = 0;
        for (int i = s.size() - 1, j = 0; i >= 0; i--, j++)
        {
            ans += (s[i] - 'A' + 1) * power26[j];
        }
        return ans;
    }
};