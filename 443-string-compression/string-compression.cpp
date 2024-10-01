class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int index = 0;
            for (int i = 0; i < chars.size();)
            {
                char letter = chars[i];
                int count = 0;
                while (i < chars.size() && chars[i] == letter)
                {
                    count++;
                    i++;
                }

                chars[index++] = letter;
                if (count > 1)
                {
                    for (auto ch: to_string(count))
                    {
                        chars[index++] = ch;
                    }
                }
            }

            return index;	// bcz index already will increased +1 due to ++ operator so it will be equal to the size of the compressod string 
        }
};