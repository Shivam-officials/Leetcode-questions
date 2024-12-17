class Solution
{
    public:

bool canDistributeHelper_Sir(vector<int> &quantity, vector<int> &occurances, int start) {
  // Base case: All customers' quantities are successfully distributed
  if (start == quantity.size()) {
    return true;
  }

  int currentQuantity = quantity[start];

  // Try to allocate the current quantity to one of the remaining frequencies
  for (auto &occur : occurances) {
    if (currentQuantity <= occur) {
      occur -= currentQuantity; // Deduct quantity
      if (canDistributeHelper_Sir(quantity, occurances, start + 1)) {
        return true; // Successfully distributed
      }
      occur += currentQuantity; // Backtrack to restore state
    }
  }
  return false; // Unable to distribute the current quantity
}

bool canDistribute(vector<int> &nums, vector<int> &quantity) {
  unordered_map<int, int> occurances; // Map to count frequencies of elements
  vector<int> count;                 // Vector to store frequencies

  // Count occurrences of each element
  for (auto elm : nums) {
    occurances[elm]++;
  }

  // Save frequencies into the count vector
  for (auto pair : occurances) {
    count.push_back(pair.second);
  }

  // Sort quantities in descending order for optimization
  sort(quantity.rbegin(), quantity.rend());

  // Helper function to check if distribution is possible
  return canDistributeHelper_Sir(quantity, count, 0);
  //   return canDistributeHelper_ME(nums,quantity,occurances,0);
}
};