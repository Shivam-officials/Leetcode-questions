class Solution
{
    public:
        int hourToMinutes(string & time)
        {
            int h1 = stoi(time.substr(0, time.find(":")));
            int m1 = stoi(time.substr(time.find(":") + 1));
            return h1 * 60 + m1;
        }

    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> minutes;
        int minDiff = INT_MAX;
        for (auto time: timePoints)
        {
            int timeInMinutes = hourToMinutes(time);

            minutes.push_back(timeInMinutes);
        }

        sort(minutes.begin(), minutes.end());

        for (int i = 0; i < minutes.size(); i++)
        {
            int diff = (i == 0) ? (1440 - minutes.back() + minutes[i]) : (minutes[i] - minutes[i - 1]);
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }
};