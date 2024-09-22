class Solution
{
    public:
        bool matchingLastKElementCOrNot(string &s, char c, int k)
        {
            int lastIndex = s.length() - 1;
            if (s.length() < k)
                return false;
            while (k--)
            {
                if (s[lastIndex] == c)
                {
                    lastIndex--;
                }
                else
                {
                    return false;
                }
            }

            return true;
        }

    string removeDuplicates(string &s, int k)
    {
        string str = "";
        int counter = k - 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (str.empty())
            {
                str.push_back(s[i]);
            }
            else if (matchingLastKElementCOrNot(str, s[i], k - 1))
            {
                for (int i = 0; i < k - 1; i++)
                {
                    str.pop_back();
                }
            }
            else
            {
                str.push_back(s[i]);
            }
        }
        return str;
    }
};