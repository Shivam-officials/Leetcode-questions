class Solution
{
    public:
        int findPairs(vector<int> &nums, int k)
        {
            set<pair<int, int>> setOfSets;
            int low = 0;
            sort(nums.begin(), nums.end());
            int high = low + 1;
            while (high <= nums.size() - 1)
            {
                int diff = nums[high] - nums[low];

                if (k == diff)
                {
                    setOfSets.insert({ nums[low],
                        nums[high] });
                    // low++;
                    high++;
                }
                else if (diff > k)
                {
                    low++;
                }
                else
                {
                    high++;
                }

                if (low == high) high++;
            }

            return setOfSets.size();
        }
};