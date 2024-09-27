class Solution {
public:

    void normalise(string &s){
        unordered_map<char,char> mapping;
        char start = 'a';
        // create the mapping
        for(auto ch:s){
            if(mapping.find(ch)==mapping.end()){
                mapping[ch] = start++;
            }
        }

        // update the string
        for(auto &ch: s){
            ch = mapping[ch];
        }

    }

    bool isIsomorphic(string s, string t) {
        if(s.length()!= t.length()) return false;
        normalise(s);
        normalise(t);
        if(s.compare(t)==0){
            return true;
        }

        return false;
    }
};