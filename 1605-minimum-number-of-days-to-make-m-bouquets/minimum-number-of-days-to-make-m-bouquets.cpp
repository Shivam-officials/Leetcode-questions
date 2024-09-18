class Solution
{
public:
    bool isPossibleSolution(vector<int>& bloomDay, int m, int k, int mid)
    {
        int flowerCount = 0;
        int bouquetCount = 0;

        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                flowerCount++;
                if (flowerCount == k)
                {
                    bouquetCount++;
                    flowerCount = 0;  // Reset flower count for the next bouquet
                }
            }
            else
            {
                flowerCount = 0;  // Reset flower count if the flower hasn't bloomed by `mid`
            }

            if (bouquetCount >= m)
            {
                return true;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k)
    {
        int n = bloomDay.size();

        // If it's impossible to make `m` bouquets with `k` adjacent flowers, return -1
        if ((long long)m * k > n)
        {
            return -1;
        }

        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        // Binary search for the minimum number of days
        while (start <= end)
        {
            int mid = start + (end - start) / 2;  // Avoid potential overflow

            if (isPossibleSolution(bloomDay, m, k, mid))
            {
                ans = mid;
                end = mid - 1;  // Try to find a smaller valid day
            }
            else
            {
                start = mid + 1;  // Increase days to find a valid solution
            }
        }

        return ans;
    }
};
