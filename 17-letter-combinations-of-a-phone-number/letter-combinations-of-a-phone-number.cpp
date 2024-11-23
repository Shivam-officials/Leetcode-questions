class Solution {
public:
    void letterCombinationSolve(string &digits, string output,int index, unordered_map<char,string> &map , vector<string> & ans){
    // base case 
    if(index >= digits.size()){
        ans.push_back(output);
        return;
    }
    string mappedString = map[digits[index]];

    for (int i = 0; i < mappedString.length(); i++) {
        letterCombinationSolve(digits, output+mappedString[i], index+1, map, ans);
    }
}
    vector<string> letterCombinations(string digits) {
 

    unordered_map<char, string> map;
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";


    vector<string>ans;
    
    if(digits == "")return ans;
    letterCombinationSolve(digits,"",0,map,ans);
    return ans;
    }
};