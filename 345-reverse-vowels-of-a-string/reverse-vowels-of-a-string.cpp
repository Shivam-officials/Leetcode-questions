class Solution
{
    public:

        bool isThisAVowel(char ch)
        {
           	// Checks if the character is an vowel (both uppercase and lowercase)
            
            return ( ch == 'a' ||  ch == 'A' ||  ch == 'e' ||  ch == 'E' ||  ch == 'i' ||  ch == 'I' ||  ch == 'o' ||  ch == 'O' ||  ch == 'u' ||  ch == 'U');
        }
    string reverseVowels(string s)
    {
        int low = 0, high = s.length() - 1;

       	// Two-pointer approach to swap only vowel
        while (low < high)
        {
           	// Skip non-vowel characters from the left
            while (!isThisAVowel(s[low]) && low < high) low++;
           	// Skip non-vowel characters from the right
            while (!isThisAVowel(s[high]) && low < high) high--;

           	// Swap valid vowel at 'low' and 'high'
            swap(s[low], s[high]);
            low++;
            high--;
        }
        return s;
    }
};