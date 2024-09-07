class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            vector<vector < int>> ans;
            for (int i = 0; i < nums.size(); i++)
            {
               	// skiping the duplicate first
               	// while(nums[i]==nums[i+1] && i < nums.size()-1){	// it will move the fix element one step ahead resulting one less low to high range to make the triplet combination so better to make sure that u avoid using the previously used values like the below to stop the fixed element moving ahead  and this will make the triplets to be unique sets of values without usign the set 
                while (i > 0 && nums[i] == nums[i - 1] && i < nums.size()-1)
                {
                    i++;
                }

                int low = i + 1;

                int high = nums.size() - 1;

                while (low < high)
                {
                   

                    int sum = nums[i] + nums[low] + nums[high];
                    if (sum == 0)
                    {
                        vector<int> temp { nums[i], nums[low], nums[high] };
                        ans.push_back(temp);

	// skip the duplicates for low
                    while (low < high && nums[low] == nums[low + 1])
                        low++;

                   	// skip the duplicates for high
                    while (low < high && nums[high] == nums[high - 1])
                        high--;

                        low++;
                        high--;
                    }
                    else if (sum > 0)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
            }
            return ans;
        }
};