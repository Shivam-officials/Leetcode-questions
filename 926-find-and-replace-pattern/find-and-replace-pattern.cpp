class Solution
{
    public:
        string normalise(string word)
        {
            char start = 'a';
            unordered_map<char, char> mapping;

           	// made the table with mapped value 
            for (auto ch: word)
            {
                if (mapping.find(ch) == mapping.end())
                {
                    mapping[ch] = start++;
                }
            }

           	// update the word acc to mapped value
            for (auto &ch: word)
            {
                ch = mapping[ch];
            }

            return word;
        }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {

        vector<string> ans;

        pattern = normalise(pattern);

        for (auto str: words)
        {
            string currentNormaliseWord = normalise(str);

            if (currentNormaliseWord.compare(pattern) == 0)
            {
                ans.push_back(str);
            }
        }

        return ans;
    }
};