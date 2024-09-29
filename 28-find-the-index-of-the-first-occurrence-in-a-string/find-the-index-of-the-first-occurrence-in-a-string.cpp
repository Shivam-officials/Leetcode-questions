class Solution {
public:
    int strStr(string haystack, string needle) {
        // if(needle.length()>haystack.length()) return -1;
        int needleIndex = 0;
        int ans = -1;
        for(int i = 0; i< haystack.length(); i++){
            int j = 0;
            if(haystack[i]==needle[j]){
                ans = i;
                while( i+j < haystack.length() && haystack[i+j]==needle[j] && j <needle.length()){
                    j++;
                }
                if(j==needle.length()) return ans;
                j = 0;
                ans = -1;
            }
            
        }
        
        return ans;
    }
};