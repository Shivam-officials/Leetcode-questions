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

        for (auto time: timePoints)
        {
            int timeInMinute = hourToMinutes(time);
            minutes.push_back(timeInMinute);
        }

        sort(minutes.begin(), minutes.end());
        int minDiff = INT_MAX;
        for (int i = 0; i < minutes.size(); i++)
        {
            int diff = (i == 0) ? (1440 - minutes.back() + minutes[0]) : (minutes[i] - minutes[i - 1]);

            minDiff = min(minDiff, diff);
        }

        return minDiff;
    }
};