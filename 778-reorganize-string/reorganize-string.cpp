class Solution
{
    public:
        string reorganizeString(string s)

    {
        int countOccurance[26] = { 0 };	// Custom hash to store frequency of each character (a-z)
        char maxOccuringElement;
        int maxOccuringElementCount = INT_MIN;

       	// NOTE: In the custom hash, when inserting the value for a character, we subtract 'a' from the character to get its index.
       	//       When retrieving the character from the hash, we add 'a' to the index to convert it back to the character.

       	// Find the most frequent character and its frequency
        for (auto ch: s)
        {
            countOccurance[ch - 'a']++;	// Inserting into the custom hash by subtracting 'a' to get the correct index
            if (maxOccuringElementCount < countOccurance[ch - 'a'])
            {
                maxOccuringElement = ch;
                maxOccuringElementCount = countOccurance[ch - 'a'];
            }
        }

       	// Place the most frequent character at every alternate index (0, 2, 4, ...)
        int index = 0;
        while (countOccurance[maxOccuringElement - 'a']--)
        {
            if (index >= s.length()) return "";	// If not enough space to place the character, return ""
            s[index] = maxOccuringElement;	// Place the most frequent character
            index += 2;
        }

       	// Reset the frequency of the most frequent character to 0
        countOccurance[maxOccuringElement - 'a'] = 0;

       	// Place the remaining characters
        for (int i = 0; i < 26; i++)
        {
            while (countOccurance[i]--)
            {
                index = (index >= s.length()) ? 1 : index;	// If even indices are filled, switch to odd indices
                s[index] = i + 'a';	// Retrieving the character from the custom hash by adding 'a' to the index
                index += 2;
            }
        }

        return s;
    }
};