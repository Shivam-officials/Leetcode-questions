class Solution
{
    public:
        string removeOccurrences(string str, string part)
        {
            while (str.find(part) != string::npos)
            {
                int index = str.find(part);
                str.erase(index, part.length());
            }

            return str;
        }
};