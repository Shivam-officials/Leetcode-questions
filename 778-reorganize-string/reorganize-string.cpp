class Solution
{
    public:
        string reorganizeString(string s)
        {
            int countOccurance[26] = { 0 };
            char maxOccuringElement;
            int maxOccuringElementCount = INT_MIN;
           	// find the most occuring element
            for (auto ch: s)
            {
                countOccurance[ch - 'a']++;
                if (maxOccuringElementCount < countOccurance[ch - 'a'])
                {
                    maxOccuringElement = ch;
                    maxOccuringElementCount = countOccurance[ch - 'a'];
                }
            }

           	// place the most occuring element at adjacent places
            int index = 0;
            while (countOccurance[maxOccuringElement - 'a']--)
            {
                if (index >= s.length()) return "";
                s[index] = maxOccuringElement;
                index += 2;
            }

            countOccurance[maxOccuringElement - 'a'] = 0;	// making it zero making it will -1 after the previous loop and when we will start replacing the rest of the character we will come accross it too and if it is -1 then our conditions make it go into infinite loop

           	// place the rest
            for (int i = 0; i < 26; i++)
            {

                while (countOccurance[i]--)
                {
                    index = index >= s.length() ? 1 : index;
                    s[index] = i + 'a';
                    index += 2;
                }
            }
            return s;
        }
};