class Solution
{
    public:

        bool bsElementFound(vector<int> nums, int start, int target)
        {
            int end = nums.size() - 1;
            if (target > nums[end])
            {
                return false;
            }
            int mid;
            while (start <= end)
            {
                mid = start + (end - start) / 2;

                if (nums[mid] == target)
                {
                    return true;
                }
                else if (nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            return false;
        }

    int findPairs(vector<int> &nums, int k)
    {
        set<pair<int, int>> sets;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int elementToFind = nums[i] + k;
            if (bsElementFound(nums, i + 1, elementToFind)) sets.insert({ nums[i],
                elementToFind });
        }
        return sets.size();
    }
};