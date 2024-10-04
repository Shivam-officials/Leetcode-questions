class Solution {
public:
    int beautySum(string s) {
        int beurtySum = 0;
  for (int i = 0; i < s.length(); i++) {
    unordered_map<char, int> mp;
    for (int j = i; j < s.length(); j++) {
      mp[s[j]]++;

      int mini = INT_MAX;
      int maxi = INT_MIN;

      for (auto entry : mp) {
        mini = min(mini, entry.second);
        maxi = max(maxi, entry.second);
      }

      beurtySum += maxi - mini;
    }
  }
  return beurtySum;
    }
};