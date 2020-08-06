struct node
{
    node *character[26];
    bool finish;
    node()
    {
        finish = false;
        for (int i = 0; i < 26; i++)
        {
            character[i] = NULL;
        }
    }
};

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    node *root = new node();
    int callnumber = 0;
    void addWord(string word, node *rootNode)
    {
        int length = word.size();
        node *currentNode = rootNode;

        for (int i = 0; i < length; i++)
        {
            if (currentNode->character[word[i] - 'a'] == NULL)
            {
                node *newNode = new node();
                currentNode->character[word[i] - 'a'] = newNode;
                currentNode = currentNode->character[word[i] - 'a'];
            }
            else
            {
                currentNode = currentNode->character[word[i] - 'a'];
            }
            if (i == length - 1)
            {
                currentNode->finish = true;
            }
        }
    }

    bool search(string word, int currentIndex, node *currentNode)
    {
        // cout << "C =" << ++callnumber << endl;
        if (currentNode == NULL)
        {
            return false;
        }
        if (currentIndex == word.size() - 1)
        {
            // cout << "HERE1" << endl;
            bool ans = false;
            if (word[currentIndex] == '.')
            {
                for (int i = 0; i < 26; i++)
                {

                    ans = ans | (currentNode->character[i] != NULL && currentNode->character[i]->finish == true);
                }
            }
            else
            {
                ans = ans | (currentNode->character[word[currentIndex] - 'a'] && currentNode->character[word[currentIndex] - 'a']->finish == true);
            }
            return ans;
        }
        bool ans = false;
        if (word[currentIndex] == '.')
        {
            for (int i = 0; i < 26 && ans != true; i++)
            {
                ans = ans | search(word, currentIndex + 1, currentNode->character[i]);
            }
        }
        else
        {
            ans = ans | search(word, currentIndex + 1, currentNode->character[word[currentIndex] - 'a']);
        }
        return ans;
    }
    WordDictionary()
    {
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        addWord(word, root);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        bool ans = false;

        ans = search(word, 0, root);

        // cout << "word = " << word <<  " ans = " << ans << endl;
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */