class Solution {
public:
    int beautySum(string s) {
      int beutySum = 0;
  for (int i = 0; i < s.length(); i++) {
    int hash[26] = {0};
    for (int j = i; j < s.length(); j++) {
      hash[s[j] - 'a']++;

      int mini = INT_MAX;
      int maxi = INT_MIN;

      for (auto count : hash) {
        if (count > 0) {
          maxi = max(maxi, count);
          mini = min(mini, count);
        }
      }

      beutySum += maxi - mini;
    }
  }
  return beutySum;
    }
};