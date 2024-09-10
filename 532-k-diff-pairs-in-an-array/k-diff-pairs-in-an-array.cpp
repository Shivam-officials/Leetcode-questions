class Solution
{
    public:
        int findPairs(vector<int> &nums, int k)
        {
            set<set < int>> setOfSets;
            int low = 0;
            sort(nums.begin(), nums.end());
            int high = low + 1;
            while (high <= nums.size() - 1)
            {
                int diff = nums[low] - nums[high];
                int absDiff = abs(diff);

                if (k == absDiff)
                {
                    setOfSets.insert({ nums[low],
                        nums[high] });
                    low++;
                    high++;
                }
                else if (absDiff > k)
                {
                    low++;
                }
                else
                {
                    high++;
                }

                if(low==high) high++;
            }

            return setOfSets.size();
        }
};