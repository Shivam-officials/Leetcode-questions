class Solution
{
    public:


    int findPairs(vector<int> &nums, int k)
    {
        set<pair<int, int>> sets;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int elementToFind = nums[i] + k;
            if (binary_search(nums.begin()+i+1,nums.end(), elementToFind)) sets.insert({ nums[i],
                elementToFind });
        }
        return sets.size();
    }
};