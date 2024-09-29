class Solution {
public:
    string palindromeAroundIt(string s, int low, int high){
        while(low>=0 && high < s.length() && s[low]== s[high]){
            low--;
            high++;
        }
        return s.substr(low+1,high-low-1);
    }
    string longestPalindrome(string s) {

        string longest = "";
        
        for(int i = 0; i< s.length();i++){

            string oddLengthLongestPalindrome = palindromeAroundIt(s,i,i);
            string evenLengthLongestPalindrome = palindromeAroundIt(s,i,i+1);

            if(longest.length()<oddLengthLongestPalindrome.length()) {
                longest = oddLengthLongestPalindrome;
            }

            if(longest.length() < evenLengthLongestPalindrome.length()){
                longest = evenLengthLongestPalindrome;
            }
        }

        return longest;
    }
};