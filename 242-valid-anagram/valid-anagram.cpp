class Solution
{
    public:

        bool isAnagram(string firstStr, string SecondStr)
        {
            vector<int> freq(256, 0);	// Frequency array for ASCII characters

            for (auto ch: firstStr)
            {
                freq[ch]++;	// Count frequency of each char in first string
            }

            for (auto ch: SecondStr)
            {
                if (freq[ch] == 0)
                    return false;	// Extra char in second string
                freq[ch]--;	// Decrement freq for matching chars
            }

            for (auto elm: freq)
            {
                if (elm != 0)
                    return false;	// Remaining unmatched chars
            }

            return true;	// Strings are anagrams
        }
};