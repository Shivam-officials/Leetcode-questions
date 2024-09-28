class Solution
{
    public:
        array<int, 256> makeFrequencyTable(string s)
        {
            array<int, 256> frequencyTable = {0};
            for (auto ch: s)
            {
                frequencyTable[ch]++;
            }
            return frequencyTable;
        }
    vector<vector < string>> groupAnagrams(vector<string> &strs)
    {
    	// HashMap to store sorted strings as keys and original strings as values (grouped anagrams)
        map<array<int, 256>, vector< string >> anagramGroupsTable;

       	// For each string, sort it and use the sorted string as the key
        for (auto currentWord: strs)
        {
            anagramGroupsTable[makeFrequencyTable(currentWord)].push_back(currentWord);	// Insert original string -> O(1) average
        }

       	// Build the result vector of grouped anagrams
        vector<vector < string>> ans;
        for (auto it: anagramGroupsTable)
        {
            ans.push_back(it.second);	// Add each group to the result -> O(n)
        }

        return ans;
    }
};