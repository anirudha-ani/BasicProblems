class Solution
{
public:
    bool isPalindrome(string s)
    {
        string analyzer = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                analyzer += (s[i] - 'A' + 'a');
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                analyzer += s[i];
            }
        }

        bool result = true;
        for (int i = 0, j = analyzer.size() - 1; i < analyzer.size() / 2; i++, j--)
        {
            if (analyzer[i] != analyzer[j])
            {
                result = false;
                break;
            }
        }
        return result;
    }
};