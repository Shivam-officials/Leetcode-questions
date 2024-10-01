class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int adjacentCount = 1;	// Tracks consecutive character count
            int index = 0;
            for (int i = 0; i < chars.size() - 1; i++)
            {
               	// If the current and next characters are the same, increase count
                if (chars[i] == chars[i + 1])
                {
                    adjacentCount++;
                    continue;	// Skip further processing until a different char is found
                }

                chars[index++] = chars[i];	// Add character directly 

                string adjacentCountString = to_string(adjacentCount);

                int j = 0;
               	// Append the count of the last group if > 1
                while (adjacentCount > 1 && j < adjacentCountString.length())
                {
                    chars[index++] = (adjacentCountString[j++]);
                }

               	// Reset count for the next group
                adjacentCount = i != chars.size() - 1 ? 1 : adjacentCount;
            }

           	// Process the last character and its count
            chars[index++] = (chars[chars.size() - 1]);
            string adjacentCountString = to_string(adjacentCount);

            int j = 0;
           	// Append the count of the last group if > 1
            while (adjacentCount > 1 && j < adjacentCountString.length())
            {
                chars[index++] = (adjacentCountString[j++]);
            }

           	// Return the new size of the compressed array
            return index;
        }
};