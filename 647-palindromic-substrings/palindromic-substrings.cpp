class Solution
{
    public:
        int palindromeSubstring(string str, int low, int high)
        {
            int count = 0;
            while (low >= 0 && high < str.length() && str[low] == str[high])
            {
                count++;
                low--;
                high++;
            }
            return count;
        }

    int palindromeSubstringCount(string s)
    {
        int ans = 0;
        for (int center = 0; center < s.length(); center++)
        {

            int oddSizePalindromeSubstring = palindromeSubstring(s, center, center);

            int evenSizePalindromeSubstring = palindromeSubstring(s, center, center + 1);

            ans += oddSizePalindromeSubstring + evenSizePalindromeSubstring;
        }
        return ans;
    }
    int countSubstrings(string s) {
        return palindromeSubstringCount(s);
    }
};