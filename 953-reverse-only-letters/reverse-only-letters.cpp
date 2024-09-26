class Solution {
public:
    bool isThisALetter(char ch){
        return (ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A') ;
    }
    string reverseOnlyLetters(string s) {
        int low= 0;
        int high = s.length()-1;
        while(low<high){
            if(isThisALetter(s[low]) && isThisALetter(s[high])){
                swap(s[low],s[high]);
                low++;
            high--;
            }else if(!isThisALetter(s[low])) low++;
            else high--;

            
        }
        return s;
    }
};