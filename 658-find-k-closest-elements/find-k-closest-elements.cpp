class Solution
{
    public:
        vector<int> findClosestElements(vector<int> &nums, int k, int x)
        {
            int low = 0;
            int high = nums.size() - 1;

            while (high - low >= k)
            {
                if (x - nums[low] > nums[high] - x)
                {

                    low++;
                }
                else
                {
                    high--;
                }
            }
            return vector<int> (nums.begin() + low, nums.begin() + high + 1);
        }
};