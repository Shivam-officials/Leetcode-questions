class Solution
{
    public:

        bool palindromeOrNot(string s, int start, int end)
        {
            while (start < end)
            {
                if (s[start] == s[end])
                {
                    start++;
                    end--;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }

    bool validPalindrome(string s)
    {
        int start = 0;
        int end = s.length() - 1;
        bool ans = true;

        while (start < end)
        {
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            {
                ans = palindromeOrNot(s, start, end - 1) || palindromeOrNot(s, start + 1, end);
                break;
            }
        }
        return ans;
    }
};