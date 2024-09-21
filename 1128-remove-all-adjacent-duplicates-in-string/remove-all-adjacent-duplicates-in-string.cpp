class Solution
{
    public:
        string removeDuplicates(string s)
        {
            string str = "";
            for (auto c: s)
            {
                if (str.empty())
                {
                    str.push_back(c);	// Push the first character
                }
                else if (c == str.back())
                {
                    str.pop_back();	// Remove the last character if it matches the current one
                }
                else
                {
                    str.push_back(c);	// Otherwise, push the current character
                }
            }
            return str;
        }
};