class Solution {
public:
    string reverseWords(string s) {
     reverse(s.begin(), s.end());
  int i = 0, start = 0, end = 0;
  while (i < s.length()) {
    // skip white spaces
    while (i < s.length() && s[i] == ' ') {
      i++;
    }

    if (i==s.length()) {
    break;
    }

    // in place the word and reverse it again to get a proper word
    while (i < s.length() && s[i] != ' ') {
      s[end++] = s[i++];
    }

    reverse(s.begin() + start, s.begin() + end);

    s[end++] = ' ';
    
    start = end;

  }
  s.resize(end - 1);
  return s;
    }
};