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
        // normallsing method

  int n = s.size();
  int m1[256] = {0}, m2[256] = {0};

  for (int i = 0; i < n; i++) {
    if (m1[s[i]] != m2[t[i]])
      return false;

    else {
      m1[s[i]] = i + 1;
      m2[t[i]] = i + 1;
    }
  }

  return true;

    }
};