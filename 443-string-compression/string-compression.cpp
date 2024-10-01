class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int adjacentCount = 1;	// Tracks the number of consecutive identical characters
            int index = 0;	// Index to place the compressed characters in the original array

           	// Iterate through the array, except for the last character
            for (int i = 0; i < chars.size() - 1; i++)
            {
               	// If the current character matches the next one, increment adjacentCount
                if (chars[i] == chars[i + 1])
                {
                    adjacentCount++;
                    continue;	// Continue without processing until a different character is found
                }

               	// Add the current character to the compressed position in the array
                chars[index++] = chars[i];

               	// If the adjacentCount is more than 1, add the count as well
                if (adjacentCount > 1)
                {
                   	// Convert the count to string and append each digit to the array
                    for (auto ch: to_string(adjacentCount))
                    {
                        chars[index++] = ch;
                    }
                }

               	// Reset adjacentCount for the next group of characters
                adjacentCount = 1;
            }

           	// Add the last character (since the loop doesn't include the last one)
            chars[index++] = chars[chars.size() - 1];

           	// Append the count for the last character group if greater than 1
            if (adjacentCount > 1)
            {
                for (auto ch: to_string(adjacentCount))
                {
                    chars[index++] = ch;
                }
            }

           	// Return the new size of the compressed array
            return index;
        }
};