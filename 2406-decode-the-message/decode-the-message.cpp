class Solution
{
    public:
        string decodeMessage(string key, string message)
        {

            unordered_map<char, char> hash;
            string letter = "abcdefghijklmnopqrstuvwxyz";
            int mapIndex = 0;
            for (int i = 0; i < key.length(); i++)
            {
                if (key[i] != ' ' && hash.find(key[i]) == hash.end())
                {
                    hash.insert(make_pair(key[i], letter[mapIndex]));
                   	// cout << hash[key[i]] <<"->"<< letter[mapIndex]<<endl;
                    mapIndex++;
                }
            }

            string ans;
            for (auto ch: message)
            {
                if (ch != ' ')
                {
                    ans.push_back(hash[ch]);
                }
                else
                {
                    ans.push_back(' ');
                }
            }
            return ans;
        }
};