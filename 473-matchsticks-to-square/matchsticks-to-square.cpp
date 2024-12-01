class Solution
{
    public:

        bool checkPossible(vector<int> &matchSticks, int index, vector<int> &sides, int &sum4th)
        {
           	// base case
            if (sides[0] > sum4th || sides[1] > sum4th || sides[2] > sum4th || sides[3] > sum4th)
            {
                return false;
            }

            if (index == matchSticks.size())
            {
                if (sides[0] == sides[1] && sides[0] == sides[2] && sides[0] == sides[3])
                {
                    return true;
                }
                return false;
            }

            int currentElement = matchSticks[index];

           	//   bool ans = false;

            for (int i = 0; i < 4; i++)
            {
                sides[i] += currentElement;
                bool ans =  checkPossible(matchSticks, index + 1, sides, sum4th);
                if (ans == true) return true;
                sides[i] -= currentElement;
            }
            return false;
        }

    bool makesquare(vector<int> &matchSticks)
    {
        int sum = accumulate(matchSticks.begin(), matchSticks.end(), 0);

        int sum4th = sum / 4;
        if (sum % 4 != 0)
        {
            return false;
        }
        vector<int> sides{ 0,0,0,0 };

        sort(matchSticks.rbegin(), matchSticks.rend());	// sort in reverse order means decreasing order

        return checkPossible(matchSticks, 0, sides, sum4th);
    }
};