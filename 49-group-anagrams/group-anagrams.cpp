class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &strs)
        {
            unordered_map<string, vector < string>> anagramGroupsTable;

           	// making the table
            for (auto ch: strs)
            {
                string s = ch;
                sort(s.begin(), s.end());
                anagramGroupsTable[s].push_back(ch);
            }

           	// making the groups
            vector<vector < string>> ans;
            for (auto it: anagramGroupsTable)
            {
                ans.push_back(it.second);
            }

            return ans;
        }
};