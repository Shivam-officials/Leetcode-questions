class Solution
{
    public:

        bool isPossbleToEat(vector<int> piles, int hours, int assumedSpeed)
        {

            long long int timeTakenToFinishPile = 0;
            for (auto pile: piles)
            {
                timeTakenToFinishPile += ceil((pile / (double) assumedSpeed));
            }
            return timeTakenToFinishPile <= hours;
        }

    int minEatingSpeed(vector<int> &pile, int hour)
    {

        int start = 1;
        int end = *max_element(pile.begin(), pile.end());
        int mid;
        int ans = 0;

        while (start <= end)
        {
            mid = (start + end) >> 1;
           	// cout << "mid is ->"<< mid <<endl;
            if (isPossbleToEat(pile, hour, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};