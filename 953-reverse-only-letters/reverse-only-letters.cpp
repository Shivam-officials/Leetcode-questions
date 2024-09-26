class Solution {
public:
    bool isThisALetter(char ch){
        return (ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A') ;
    }
    string reverseOnlyLetters(string s) {
        int low= 0;
        int high = s.length()-1;
        while(low<high){
            while(!isThisALetter(s[low]) && low<high) {
low++;
            } 

             while(!isThisALetter(s[high] ) && low<high) {
                high--;
             }
            swap(s[low],s[high]);
            low++;
            high--;
        }
        return s;
    }
};