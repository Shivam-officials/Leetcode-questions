class Solution
{
    public:
        void normalise(string & word)
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
        }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {

        vector<string> ans;

       	// normalise the pattern 
        normalise(pattern);

       	// normalise every current element and if it matches with the normalised pattern add the before normalised current element in the ans vector
        for (auto str: words)
        {
            string currentWord = str;
            normalise(str);

            if (str.compare(pattern) == 0)
            {
                ans.push_back(currentWord);
            }
        }

        return ans;
    }
};