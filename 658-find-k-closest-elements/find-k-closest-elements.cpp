class Solution
{
    public:

        vector<int> findClosestElements(vector<int> &nums, int k, int x)
        {

           	// Find the index of the first element that is not less than x using lower_bound
            auto highIt = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            int n = nums.size();

           	// Set high to the found index, or the last element if x is greater than all elements
            int high = highIt > n - 1 ? n - 1 : highIt;
            if (high == 0 && n != 1)
            {
                high++;
            }

           	// Set low to one element before high
            int low = high - 1;

           	// Expand the window from the middle until the window contains exactly k elements
            while (k--)
            {
                if (low < 0)
                {
                    high++;	// If low is out of bounds, increase high
                }
                else if (high >= n)
                {
                    low--;	// If high is out of bounds, decrease low
                }
                else if (x - nums[low] <= nums[high] - x)
                {
                    low--;	// If the left element is closer, move left
                }
                else
                {
                    high++;	// Otherwise, move right
                }
            }

           	// Return the subarray between low and high (inclusive) containing k closest elements
            return vector<int> (nums.begin() + low + 1, nums.begin() + high);
        }
};