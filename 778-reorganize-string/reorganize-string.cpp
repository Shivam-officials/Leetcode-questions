class Solution
{
    public:
        string reorganizeString(string s)
        {
            unordered_map<char, int> count;
           	// find the most occusring element
            int maxOccuringElementCount = INT_MIN;
            char maxOccuringElement;
            for (auto ch: s)
            {
                count[ch]++;
                if (maxOccuringElementCount < count[ch])
                {
                    maxOccuringElementCount = count[ch];
                    maxOccuringElement = ch;
                }
            }

           	// place the most occuring element
            int index = 0;
            while (count[maxOccuringElement]--)
            {
                if (index >= s.length())
                {
                    return "";
                }

                s[index] = maxOccuringElement;
                index += 2;
            }

            count[maxOccuringElement] = 0;
           	// place the rest
            for (auto &occurance: count)
            {
                while (occurance.second--)
                {
                   	// cout << occurance.second<<endl;
                    index = index >= s.length() ? 1 : index;

                    s[index] = occurance.first;
                    index += 2;
                }
            }
           	// cout << s;
            return s;
        }
};