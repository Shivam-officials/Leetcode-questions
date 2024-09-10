class Solution
{
    public:
        int findPairs(vector<int> &nums, int k)
        {
            int count = 0;
            set<set < int>> setOfSets;
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    auto diff = nums[i] - nums[j];
                    if ((abs(diff) == k) && (setOfSets.find({ nums[i],
                            nums[j] }) == setOfSets.end()))
                    {
                        count++;

                        setOfSets.insert({ nums[i],
                            nums[j] });
                    }
                }
            }
            return setOfSets.size();
        }
};