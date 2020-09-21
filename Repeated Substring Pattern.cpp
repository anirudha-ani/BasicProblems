class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        bool ans = false;
        int slength = s.size();
        for (int i = 1; i <= slength / 2; i++)
        {
            if (slength % i == 0)
            {
                ans = true;
                for (int j = 0; j < slength; j++)
                {
                    if (s[j] != s[j % i])
                    {
                        ans = false;
                        break;
                    }
                }
                if (ans == true)
                {
                    return ans;
                }
            }
        }
        return ans;
    }
};