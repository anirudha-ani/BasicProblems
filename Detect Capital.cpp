class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        bool small = false;
        bool capital = false;
        for (int index = 0; index < word.size(); index++)
        {

            if (word[index] >= 'A' && word[index] <= 'Z')
            {
                if (index != 0)
                {
                    capital = true;
                }
            }
            else
            {
                small = true;
            }
        }
        if (capital && small)
        {
            return false;
        }
        return true;
    }
};